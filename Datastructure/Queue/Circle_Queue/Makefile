# 2021. 01. 16
# Creater : Gunhee Choi
# This file is MakeFile

CC=gcc
CFLAGS=-g -Wall
OBJS= Sim_Circle_Queue.o main.o
TARGET=Main

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

Sim_Circle_Queue.o: Sim_Circle_Queue.h Sim_Circle_Queue.c 
main.o: basic.h Sim_Circle_Queue.h main.c

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)