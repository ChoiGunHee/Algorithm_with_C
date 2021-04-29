/**
* 2021. 04. 29
* Creater : Gunhee Choi
* Problem Number : 10828
* Title : 스택

* Problem :
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다. 

* Input :
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

	14
	push 1
	push 2
	top
	size
	empty
	pop
	pop
	pop
	size
	empty
	pop
	push 3
	empty
	top

* Output :
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

	2
	2
	0
	2
	1
	-1
	0
	1
	-1
	0
	3

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

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
	int n;
	char p_str[10];
	int temp;
	int i;

	StackType s;
	init_stack(&s, MAX_SIZE);

	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%s", p_str);
		
		if( strcmp("push", p_str) == 0 ) {
			scanf("%d", &temp);
			push(&s, temp);
		} else if( strcmp("top", p_str) == 0 ) {
			printf("%d\n", peek(&s));
		} else if( strcmp("size", p_str) == 0 ) {
			printf("%d\n", size(&s));
		} else if( strcmp("pop", p_str) == 0 ) {
			printf("%d\n", pop(&s));
		} else if( strcmp("empty", p_str) == 0 ) {
			printf("%d\n", is_empty(&s));
		}
	}
	
	return 0;	
}