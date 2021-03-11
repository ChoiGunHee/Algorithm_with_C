# 2021. 01. 16
# Creater : Gunhee Choi
# This file is MakeFile

CC=gcc
CFLAGS=-g -Wall
OBJS= Sim_Stack.o Check_Matching.o main.o
TARGET=Main

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

Sim_Stack.o: Sim_Stack.h Sim_Stack.c
Check_Matching.o : Sim_Stack.h Check_Matching.h Check_Matching.c
main.o: basic.h Sim_Stack.h Check_Matching.h main.c

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)