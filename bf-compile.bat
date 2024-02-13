gcc -c .\main.c
gcc -c .\bf-interpreter.c
gcc -c .\stack.c
gcc -o .\interpreter.exe .\main.o .\bf-interpreter.o .\stack.o