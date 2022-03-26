## How to Install Anaconda on Ubuntu

```make
1. https://www.anaconda.com/products/individual
2. 다운로드를 누르면 *.sh 파일이 다운로드 될 것이다.
3. 다운로드가 완료되면 위치를 이동시키도록 한다.
   cd 배치하고싶은위치
   mv ~/Downloads/Anaconda3-2021.11-Linux-x86_64.sh ./
4. 권한 부여
   chmod 755 ./Anaconda3-2021.11-Linux-x86_64.sh
5. 실행
   bash Anaconda3-2021.11-Linux-x86_64.sh
6. 앤터
7. q
8. yes
9. 앤터
10. vi ~/.bashrc
11. source ~/.bashrc
12. conda --version
13. 만약 여기서 버전 정보가 나오지 않는다면 경로 설정이 누락되었다는 뜻이다.
    vi ~/.bashrc 를 입력하고 맨 아래쪽에 아래를 입력한다.
    
    export PATH="/home/본인계정이름/anaconda3/bin:$PATH"
14. cd ~
    anaconda3/bin/python --version
    anaconda3/bin/conda --version


```





