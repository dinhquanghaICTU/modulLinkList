
CC = gcc
CFLAGS = -Iinc
SRC = src/main.c src/modulLinkList.c
OUT = app

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)