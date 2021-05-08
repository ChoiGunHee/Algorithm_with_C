# 2021. 05. 08
# Creater : Gunhee Choi
# This file is MakeFile

CC=gcc
CFLAGS=-g -Wall
OBJS= Sim_Deque.o main.o
TARGET=Main

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

Sim_Deque.o: Sim_Deque.h Sim_Deque.c 
main.o: basic.h Sim_Deque.h main.c

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)