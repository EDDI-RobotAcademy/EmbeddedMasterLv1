# 기계어를 분석합시다!

## 몇 가지 필수적인 사항들

```make
ax: 함수의 리턴값을 저장함
bp: 스택의 기준 값
sp: 스택의 최상위 값
ip: 다음에 실행할 메모리 위치를 가르킴

스택은 거꾸로 자란다.
```

## 위 사항을 기반으로 분석

```make
   0x000055555555515b <+0>:	endbr64
   endbr64의 경우엔 크게 신경쓰지 않아도 됩니다.

=> 0x000055555555515f <+4>:	push   %rbp
   push의 역할: 스택 최상위(rsp)에
   뒤쪽의 값(현재 케이스는 rbp)를 저장한다.

   1) 이를 분석하기 위해 거쳐야 하는 절차는 ?
   1-1) 현재 rbp 값을 확인
   1-2) 현재 rsp 값을 확인
   1-3) si를 통해 명령어 단위로 1줄 실행
   1-4) x $rsp를 통해서 현재 스택의 최상위에
        rbp 값이 잘 들어갔는지 확인

   0x0000555555555160 <+5>:	mov    %rsp,%rbp
   mov의 역할: 좌측값을 우측으로 대입한다.

   2) 이 코드를 분석하기 위해 거쳐야 하는 절차는 ?
   2-1) 현재 rbp 값을 확인
   2-2) si를 통해 명령어 단위로 한 줄 실행
   2-3) rbp 값이 rsp 로 변경되었는지 확인

   <1> 현재 여기까지의 절차를 Stack Frame을 생성한다고 말한다.

   0x0000555555555163 <+8>:	sub    $0x10,%rsp
   sub의 역할: 우측에서 좌측을 빼서 우측에 적용

   3) 이 코드를 분석하기 위해 거쳐야 하는 절차는 ?
   3-1) 현재 rsp 값을 확인
   3-2) si
   3-3) 다시 rsp 값을 확인하여 16이 빠졌는지 확인한다.

   <2> 결론적으로 이 코드는 main 함수 내부에서
       사용할 Stack 공간을 할당하는 작업이다.

   0x0000555555555167 <+12>:	movl   $0x3,-0x8(%rbp)
   movl의 역할: mov에 l이 붙은 형태로 4바이트 데이터를 처리한다.

   4) 이 코드의 분석법
   4-1) x rbp - 0x8 로 해당 메모리 위치의 내용을 확인한다.
   4-2) si
   4-3) x rbp - 0x8 에서 숫자 3이 나오는 것을 확인한다.

   <3> 결론: main 함수내 어떤 변수에 숫자값 3을 할당함

   0x000055555555516e <+19>:	mov    -0x8(%rbp),%eax

   5) 이 코드의 분석법
   5-1) eax에 rbp - 0x8의 값인 숫자 3이 배치되는지 여부 파악

   0x0000555555555171 <+22>:	mov    %eax,%edi

   6) 분석법
   6-1) eax의 내용이 edi로 대입되는지 확인

   0x0000555555555173 <+24>:	callq  0x555555555149 <test_func>
   callq의 역할: 함수 호출(복귀 주소를 저장하고 함수로 이동)

   7) 분석법
   7-1) 복귀 주소(다음에 실행해야하는 주소)가
        Stack에 저장되는지 확인
   7-2) 그리고 test_func으로 이동했는지 확인

   0x0000555555555178 <+29>:	mov    %eax,-0x4(%rbp)

   <8> 복귀 주소로 돌아와서 끝 ?
       eax에 저장된 리턴값을 rbp - 0x4로
	   즉 main 함수내의 지역 변수 공간에 저장한다.
	   이것이 C 언어로는 result = test_func() 형식으로 나타난다.

   0x000055555555517b <+32>:	mov    -0x4(%rbp),%eax
   0x000055555555517e <+35>:	mov    %eax,%esi
   0x0000555555555180 <+37>:	lea    0xe7d(%rip),%rdi        # 0x555555556004

   <9> 여기서 우리가 체크해야 하는 부분은 ?
       0x5555....556004에 문자열 상수 값이 배치되어 있으므로
	   char 형의 1바이트 배열이 배치되어 있음을 확인해야 한다.
	   이를 수행하기 위해 아래와 같은 명령을 활용하였다.
	   x/c 0x555...5556004

	   이것까지 확인하면 전반적인 컴퓨터의 전체 동작을
	   어느정도 꿰게 되었다 해도 과언이 아닐 것이다.

   0x0000555555555187 <+44>:	mov    $0x0,%eax
   0x000055555555518c <+49>:	callq  0x555555555050 <printf@plt>
   0x0000555555555191 <+54>:	mov    $0x0,%eax
   0x0000555555555196 <+59>:	leaveq
   0x0000555555555197 <+60>:	retq





   test_func 함수의 어셈블리
=> 0x0000555555555149 <+0>:		endbr64 
   무시한다.

   0x000055555555514d <+4>:		push   %rbp
   0x000055555555514e <+5>:		mov    %rsp,%rbp

   <4> 새로운 test_func 함수의 Stack Frame을 생성한다.

   0x0000555555555151 <+8>:		mov    %edi,-0x4(%rbp)

   8) 여기서 주의할 부분이라면
      사실 Calling Convention이라는 부분이 있어
	  이를 고려 해줘야 한다는 것이다.

	  실제로 하드웨어 자원은 유한 ? 무한 ?
	  유한하다.

	  그러므로 활용할 수 있는 레지스터의 개수도 ?
	  유한하다.

	  메모리 계층 구조(Memory Hierarchy) 관점에서 레지스터는 매우 빠르다.
	  그러나 개수가 유한하다.
	  그렇다면 이를 효율적으로 써야 할까 ? 막 써야 할까 ?
	  효율적으로 써야 한다.
	  이와 같은 이유로 함수 호출시 입력 몇 개 까지는 레지스터로 입력 받고
	  입력이 일정 개수 이상이 되면 Stack에 저장해서 보내게 된다.
	  이러한 함수 호출 규약을 Calling Convention 이라고 한다.

   0x0000555555555154 <+11>:	mov    -0x4(%rbp),%eax
   0x0000555555555157 <+14>:	add    %eax,%eax
   add의 역할: 덧셈하여 값을 적용

   <5> eax에 리턴값인 6이 저장됨

   0x0000555555555159 <+16>:	pop    %rbp

   <6> 현재 스택의 최상위에 저장된 값은
       이전(main) 함수의 Stack 기준점이다.
	   이를 복원해주는 작업이 된다.

   0x000055555555515a <+17>:	retq

   <7> 현재 스택의 최상위에 저장된 값을
       ip 레지스터에 설정해주는 작업을 한다.
	   결론적으로 이로 인해 복귀 주소로 복귀를 하게 된다.
```
