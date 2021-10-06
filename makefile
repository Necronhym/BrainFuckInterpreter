IN=main.c
OUT=brainfuck
CC=gcc
target:
	$(CC) $(IN) -o $(OUT)
