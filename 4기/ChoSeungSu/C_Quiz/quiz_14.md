## 함수 Call 어셈블리 특징
- - -
함수를 호출할 때는 Call 명령을 수행한다.

call 명령은 push + jmp 명령을 수행한다. 

* IP(Instruction pointer)
로 함수를 호출했던 위치를 저장하고

*  return 이후 jmp를 통해 다음 명령으로 이동할 수 있도록 함 

함수 호출 과정을 보면 
1. call 명령을 통한 호출한 위치 IP를 저장 
2.  Push ebp 명령을 통한 
   이전 스택 프레임의 BP 값 저장 
3.  mov ebp esp 명령을 통해 ESP(스택 포인터)를 이동 
    
    새로운 함수의 EBP가 설정 되고 새로운 스택 공간이 할당 됨.
- - - 
### Return 할 때
1. mov esp ebp 명령
* 스택 프레임 회수 

2. pop ebp 명령
* 저장했던 이전 함수의 EBP를 원래 위치의 EBP로 설정

3. ret
* 저장했던 EIP 값을 통해 이전 실행 위치로 이동 