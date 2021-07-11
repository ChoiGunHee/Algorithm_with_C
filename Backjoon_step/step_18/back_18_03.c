/**
* 2021. 07. 11
* Creater : Gunhee Choi
* Problem Number : 9012
* Title : 괄호

* Problem :
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 

여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나타내어야 한다. 

* Input :
입력 데이터는 표준 입력을 사용한다. 입력은 T개의 테스트 데이터로 주어진다. 입력의 첫 번째 줄에는 입력 데이터의 수를 나타내는 정수 T가 주어진다. 각 테스트 데이터의 첫째 줄에는 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다. 

	6
	(())())
	(((()())()
	(()())((()))
	((()()(()))(((())))()
	()()()()(()()())()
	(()((())()(

* Output :
출력은 표준 출력을 사용한다. 만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 

	NO
	NO
	YES
	NO
	YES
	NO

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char datatype;

typedef struct {
	datatype * data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType * stack) {
	stack->top = -1;
	stack->capacity = 1;
	stack->data = (char *) malloc(stack->capacity * sizeof(int));
}

int is_full(StackType * stack) {
	return (stack->top == (stack->capacity - 1));
}

int is_empty(StackType * stack) {
	return (stack->top == -1);
}

int push(StackType * stack, char data) {
	if(is_full(stack)) {
		stack->capacity *= 2;
		stack->data = (char * ) realloc(stack->data, stack->capacity * sizeof(int));
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

int check_matching(const char * input) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(input);
	init_stack(&s);
	
	for(i=0; i<n; i++) {
		ch = input[i];
		switch (ch) {
			case '(' :
			case '[' :
			case '{' :
				push(&s, ch);
				break;
			case ')' :
			case ']' :
			case '}' :
				if(is_empty(&s)) return 0;
				else {
					open_ch = pop(&s);
					if( (open_ch == '(' && ch != ')') ||
					  	(open_ch == '(' && ch != ')') ||
					    (open_ch == '(' && ch != ')') ) {
						return 0;
					}//if
				break;
				}//else
		}//switch
	}//for
	
	if( !is_empty(&s) ) return 0;
	return 1;
}

int main(void) {
	int n;
	char p_str[100];
	int i;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++) {
		scanf("%s", p_str);
		if(check_matching(p_str)) printf("YES\n");
		else printf("NO\n");
	}

	return 0;	
}