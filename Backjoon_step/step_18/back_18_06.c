/**
* 2021. 07. 11
* Creater : Gunhee Choi
* Problem Number : 17298
* Title : 스택 수열

* Problem :
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.
예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

* Input :
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

	4
	3 5 2 7

* Output :
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

	5 7 7 -1

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef int datatype;

typedef struct {
	datatype * data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType * stack, int size) {
	stack->top = -1;
	stack->capacity = size;
	stack->data = (int *) malloc(stack->capacity * sizeof(int));
}

int is_full(StackType * stack) {
	return (stack->top == (stack->capacity - 1));
}

int is_empty(StackType * stack) {
	if( stack->top == -1 ) return 1;
	else return 0;
}

int push(StackType * stack, int data) {
	if(is_full(stack)) {
		stack->capacity *= 2;
		stack->data = (int * ) realloc(stack->data, stack->capacity * sizeof(int));
	}
	
	stack->data[++(stack->top)] = data;
}

int pop(StackType * stack) {
	if(is_empty(stack) == 1) {
		return -1;
	} else {
		return stack->data[(stack->top)--];
	}
}

int peek(StackType * stack) {
	if(stack->top == -1) return -1;
	else return stack->data[stack->top];
}

int size(StackType * stack) {
	if(stack->top == -1) return 0;
	else return stack->top + 1;
}

int main(void) {
	
	return 0;	
}