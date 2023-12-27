# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: Node Arbre exec

exec: Node Arbre
	./Node
	./Arbre

Node: node.c node.h
	$(CC) $(CFLAGS) -w node.c -o Node

Arbre: arbre.c arbre.h
	$(CC) $(CFLAGS) -o  Arbre arbre.c 

clean:
	rm -f Node
	rm -f Arbre
	
