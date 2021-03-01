/* 2021. 03. 01
 * Creater : Gunhee Choi
 * This file is Stack Simulation
 */

#include "Sim_Stack.h"

void init_stack(StackType * stack) {
	stack->top = -1;
	stack->capacity = 1;
	stack->data = (int *) malloc(stack->capacity * sizeof(int));
}

int is_full(StackType * stack) {
	return (stack->top == (stack->capacity - 1));
}

int is_empty(StackType * stack) {
	return (stack->top == -1);
}

int push(StackType * stack, int data) {
	if(is_full(stack)) {
		stack->capacity *= 2;
		stack->data = (int * ) realloc(stack->data, stack->capacity * sizeof(int));
	}
	
	stack->data[++(stack->top)] = data;
}

int pop(StackType * stack) {
	if(is_empty(stack)) {
		printf("스택 에러, 공백!\n");
	} else {
		return stack->data[(stack->top)--];
	}
}

int peek() {
	printf("func : peek\n");
}