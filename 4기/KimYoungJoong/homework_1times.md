LINUX 명령어

편집모드
mkdir(make directory) : 디레곹리 생성
ls(list) : 현재 위치에 존재하는 파일, 디렉토리 목록
pwd(password) : 현재 디렉토리 위치 => '/'   / <- 뜻 root 디렉토리
cd(change directory) : 디렉토리 위치 변경
사용법 cd .. -> 하위폴더로 이동
       cd 폴더명 -> 폴더로 진입
'.' 현재 디렉토리
'..' 하위 디렉토리
ex) 현재 내위치가 '/emlv1/kyj/test' 라면
    '/emlv1/kyj/c'로 이동할 때
    아래와 같은 명령을 작성 할 수 있음
    cd ../c => 이동 완료
mautilus /  : GUI상태로 현재 디렉토리를 볼수 있음
vi : 편집기 =>커맨드, 편집
              (esc)   [i,a(현재위치) , shift + i(라인 맨앞), shift + a(라인 맨뒤)]
커맨드 모드에서 ':mq'  => 저장하고 나가기
커맨드 모드에서 y숫자y => 숫자만큼 라인복사
커맨드 모드에서 d숫자d => 숫자만큼 삭제
커맨드 모드에서 u => 뒤로 가기
커맨드 모드에서 y => 앞으로 가기
커맨드 모드에서 p => 붙여넣기

컴파일 방법
1. gcc *.c -> a.out
실행 ,/a.out

2. gcc -o variable
variable.c
