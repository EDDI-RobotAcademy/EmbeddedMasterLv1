# EmbeddedMasterLv1
임베디드 마스터 레벨1

## Prerequisites

```make
1. Ubuntu 20.04 설치
```

## Environment Settings

```make
1. sudo apt-get update
2. sudo apt-get install vim
3. sudo apt-get install git
4. sudo apt-get install build-essential
```

## Env Set Confirm

```make
1. gcc -v
2. git --version
```

## GitHub

```make
1. github에서 회원 가입 진행!
2. 로그인 진행
3. git 계정명 및 계정 이메일을 알려주세요.
4. 초대 메시지가 이메일로 날라오면 승인해서 저장소에 조인해주세요.
```

## Post Work

```make
1. Embedded Master Lv1 저장소를 자신의 계정으로 fork 합니다.
2. 복사된 저장소에서 초록색 code 부분을 클릭하여 저장소 링크를 복사합니다.
3. git clone 복사한주소 (이후에 디렉토리가 만들어짐)
4. cd 디렉토리명
5. git remote -v (이를 통해서 저장소의 위치 확인 - 자신의 계정명이 보여야함)
6. git remote add upstream 원본주소
7. git remote -v (이제 여기서 origin은 자신의 계정명, upstream엔 Embedded Master가 보여야함)
8. git fetch upstream
9. git merge upstream/main
```

위와 같은 방식을 통해서 작업한 사항들을 업데이트할 수 있습니다.

## 숙제 제출 방법

```make
1. 제공한 양식에 맞춰주세요.
2. 공유한 모범 사례들을 참고하여 작성합니다.
3. git에 용량 제한이 있기 때문에 작업은 pdf로 변환하여 올려주세요.
4. 실제 작업한 내용을 git에 업로드 하고 PR까지 완료합니다.
5. 원본 저장소에 PR이 잘 요청되었는지 확인합니다.
```

## git에 코드 및 자료 업로드 방법

```make
1. 먼저 자신이 작업한 내용이 있다면 이 내용을 적용해야 합니다.
   git status - 이를 통해 변경 사항이 있는지 체크합니다.

2. 변경 사항이 있다면 git add (코드 혹은 문서)를 통해 내용을 추가합니다.
   ex) git add test.c

3. 변경 사항을 커밋하여 적용합니다.
   git commit -am "이름: 몇회차 숙제(작업한 내용)"

4. git push origin main

5. 아이디와 이전에 발급했던 토큰(token)을 비밀번호에 작성합니다.

6. 원본에 적용되어 있는 내용들을 fetch 받아옵니다.
   git fetch upstream

7. 원본의 내용을 사본에 업데이트 합니다.
   git merge upstream/main

8. github.com에서 자신의 사본으로 이동합니다.

9. 초록색 Code 버튼 하단에 Fetch가 있고 Contribute가 보일텐데
   Contribute를 누르고 Open Pull Request를 누릅니다.

10. 우측에 Create Pull Request를 누릅니다.

11. 하단에 Create Pull Request를 다시 한 번 누릅니다.

12. 원본에 PR요청이 잘 들어갔는지 확인합니다.
```
