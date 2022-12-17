# How to install Vue on Ubuntu 20.04

```make
sudo apt-get update
sudo apt-get upgrade

curl -sL https://deb.nodesource.com/setup_16.x | sudo bash -
sudo apt-get install nodejs
```

이후 아래 명령을 통해 nodejs가 잘 설치 되었는지 확인합니다.  

```make
node -v
```

그리고 최신 npm으로 업그레이드 합니다.  

```make
npm install npm@latest -g
npm -v
```

vue-cli를 설치합니다.  

```make
npm install -g @vue/cli
vue --version
```

vue 프로젝트를 생성합니다.  

```make
vue create vue-project
```


