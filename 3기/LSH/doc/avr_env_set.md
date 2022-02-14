## AVR 환경 설정을 위한 준비

```make
sudo apt-get update
sudo apt-get install codeblocks
```

## AVRdude 설치

```make
sudo add-apt-repository ppa:pmjdebruijn/avrdude-release
sudo apt-get update
sudo apt-get install libc6-dev-i386
sudo apt-get install binutils-avr gcc-avr avr-libc avrdude libc6-dev-i386
```

## ISP Programmer 검사

```make
dmesg
```

## Codeblocks 시작하기

```make
codeblocks
```

## AVR Project 구성

```make
실제 프로젝트를 배치할 위치로 이동합니다.
필요하다면 디렉토리를 만듭니다.

cd ~
mkdir -p proj/avr

codeblocks 에서 
File -> New -> Project -> AVR Project

Next

Project title: blink
Folder to create project in: 프로젝트 경로
Project filename: blink.cbp
Resulting filename: 프로젝트 경로/blink/blink.cbp
Next

Uncheck: Create "Debug" configuration
Next

Please choose a processor for this project...: atmega328p
Uncheck: Create Fuse, Lock, Signature files (.fuse .lock .sig)
Finish
```

## 프로그램 Flash 하기

```make
hex 파일이 있는 위치로 이동합니다.

sudo avrdude -c avrisp2 -p m328p -U flash:w:blink.hex
```

