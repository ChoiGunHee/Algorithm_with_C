# 2021. 01. 16
# Creater : Gunhee Choi
# This file is MakeFile

CC=gcc
CFLAGS=-g -Wall
OBJS=main.o Sim_Stack.o Linked_List.o
TARGET=Main

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: basic.h Sim_Stack.h Linked_List.h main.c
Sim_Stack.o: Sim_Stack.h Sim_Stack.c 
Linked_List.o: Linked_List.h Linked_List.c

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)