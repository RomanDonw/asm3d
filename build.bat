@echo off

nasm -f win64 -I./include src/main.asm -o main.o

if not exist main.o goto error
	gcc -fPIC -L ./lib main.o ./lib/libglfw3.a ./lib/libglad.a -o main.exe -lOpenGL32 -lgdi32
	
	del main.o

	goto end
:error
	set ERRORLEVEL=1

:end