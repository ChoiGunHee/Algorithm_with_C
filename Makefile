# 2021. 01. 16
# Creater : Gunhee Choi
# This file is MakeFile

CC=gcc
CFLAGS=-g -Wall
OBJS= Sim_Stack.o Linked_List.o main.o
TARGET=Main

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

Sim_Stack.o: Sim_Stack.h Sim_Stack.c 
Linked_List.o: Linked_List.h Linked_List.c
main.o: basic.h Sim_Stack.h Linked_List.h main.c

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)