/**
* 2021. 07. 11
* Creater : Gunhee Choi
* Problem Number : 1874
* Title : 스택 수열

* Problem :
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

* Input :
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

	8
	4
	3
	6
	8
	7
	5
	2
	1

* Output :
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.

	+
	+
	+
	+
	-
	-
	+
	+
	-
	+
	+
	-
	-
	-
	-
	-

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
	int n;
	char * results;
	int * arr;
	int t;
	int count = 0;
	int arr_count = 0;
	StackType s;
	init_stack(&s, MAX_SIZE);

	int i;
	
	scanf("%d", &n);
	results = (char *) malloc(sizeof(char) * n * 2);
	arr = (int *) malloc(sizeof(int) * n);
	
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	for(i=1; i<=n; i++) {
		push(&s, i);
		results[count++] = '+';
		
		while(1) {
			//printf("peek : %d\n", peek(&s));
			if(!is_empty(&s) && arr[arr_count] == peek(&s)) {
				pop(&s);
				results[count++] = '-';
				arr_count++;
			} else {
				break;
			}
		}
	}
	
	if(is_empty(&s)) {
		for(i=0; i<n*2; i++)
			printf("%c\n", results[i]);
	} else {
		printf("NO\n");
	}
	
	return 0;	
}