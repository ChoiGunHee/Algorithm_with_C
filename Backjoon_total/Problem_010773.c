/**
* 2021. 04. 30
* Creater : Gunhee Choi
* Problem Number : 10773
* Title : 제로

* Problem :
나코더 기장 재민이는 동아리 회식을 준비하기 위해서 장부를 관리하는 중이다.
재현이는 재민이를 도와서 돈을 관리하는 중인데, 애석하게도 항상 정신없는 재현이는 돈을 실수로 잘못 부르는 사고를 치기 일쑤였다.
재현이는 잘못된 수를 부를 때마다 0을 외쳐서, 가장 최근에 재민이가 쓴 수를 지우게 시킨다.
재민이는 이렇게 모든 수를 받아 적은 후 그 수의 합을 알고 싶어 한다. 재민이를 도와주자!

* Input :
첫 번째 줄에 정수 K가 주어진다. (1 ≤ K ≤ 100,000)
이후 K개의 줄에 정수가 1개씩 주어진다. 정수는 0에서 1,000,000 사이의 값을 가지며, 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
정수가 "0"일 경우에 지울 수 있는 수가 있음을 보장할 수 있다.

	4
	3
	0
	4
	0

* Output :
재민이가 최종적으로 적어 낸 수의 합을 출력한다. 최종적으로 적어낸 수의 합은 231-1보다 작거나 같은 정수이다.

	0

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
	int K;
	StackType s;
	init_stack(&s, MAX_SIZE);
	
	int temp;
	int result = 0;
	int i;
	
	scanf("%d", &K);
	
	for(i=0; i<K; i++) {
		scanf("%d", &temp);
		if(temp == 0) pop(&s);
		else push(&s, temp);
	}
	
	while( peek(&s) != -1 ) {
		result += pop(&s);
	}
	
	printf("%d\n", result);
	
	return 0;	
}