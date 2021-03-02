/* 2021. 03. 01
 * Creater : Gunhee Choi
 * This file is Stack Simulation header
 */

#ifndef SIM_STACK_H
#define SIM_STACK_H
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

#include "basic.h"

typedef struct {
	int * data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType * stack);
int is_full(StackType * stack);
int is_empty(StackType * stack);
int push(StackType * stack, int data);
int pop(StackType * stack);

#endif