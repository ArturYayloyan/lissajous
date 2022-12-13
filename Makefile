.SILENT:
SHELL=/bin/bash
.SHELLFLAGS=--norc --noprofile -e -u -o pipefail -c
run_win:
	gcc -std=c99 -Wall -Wpedantic -o  dist/lissajous.exe lissajous.c 
	./dist/lissajous.exe

run_lin:
	gcc -std=c99 -Wall -Wpedantic -o  dist/lissajous.out lissajous.c 
	dist/lissajous.out

run_web: 
	git clone https://github.com/emscripten-core/emsdk.git
	cd emsdk/ && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc lissajous.c -o lissajous.html
	npm i http-server -g

runserver:
	cd ../emsdk && http-server