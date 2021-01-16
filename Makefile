CC=gcc
CFLAGS=-g -Wall
OBJS=main.o Sim_Stack.o
TARGET=Main

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

main.o: Sim_Stack.h main.c
Sim_Stack.o: Sim_Stack.h Sim_Stack.c 

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)