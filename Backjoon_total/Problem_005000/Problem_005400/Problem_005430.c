/**
* 2021. 08. 30
* Creater : Gunhee Choi
* Problem Number : 5337
* Title : 웰컴

* Problem :
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.

함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.

함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수이다.

배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.

각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.

다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)

다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 수가 주어진다. (1 ≤ xi ≤ 100)

전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

	4
	RDD
	4
	[1,2,3,4]
	DD
	1
	[42]
	RRD
	6
	[1,1,2,3,5,8]
	D
	0
	[]

* Output :
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.

	[2,1]
	error
	[1,2,3,5,8]
	error
	
**/

#include <stdio.h>
#include <string.h>
#define MAX_QUEUE_SIZE 100001

typedef int element;

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} DequeType;

void init_queue(DequeType * queue) {
	queue->rear = queue->front = 0;
}

int is_full(DequeType * queue) {
	return  ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

int is_empty(DequeType * queue) {
	return (queue->front == queue->rear);
}

void deque_print(DequeType * queue) {
	int i;
	
	printf("QUEUE(front=%d rear=%d) = ", queue->front, queue->rear);
	if( !is_empty(queue)) {
		i = queue->front;
		do {
			i = (i+1) % MAX_QUEUE_SIZE;
			printf("%d | ", queue->data[i]);
			if(i == queue->rear) break;
		} while(i != queue->front);
	}
	printf("\n");
}

void add_front(DequeType * q, element item) {
	if(is_full(q))
		printf("Queue is Full\n");
	
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(DequeType * q) {
	if(is_empty(q))
		printf("Queue is empty\n");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

element get_front(DequeType * q) {
	if(is_empty(q))
		printf("Queue is empty\n");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_rear(DequeType * q, element item) {
	if(is_full(q)) 
		printf("Queue is Full\n");
	
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_rear(DequeType * q) {
	int prev = q->rear;
	if(is_empty(q))
		printf("Queue is empty\n");
	
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType * q) {
	if(is_empty(q))
		printf("Queue is empty\n");
	
	return q->data[q->rear];
}

int main(void) {
	int T;
	int n;
	char instruct[100001];
	char arr_str[200];
	int arr[200];
	int tmp_num[3];
	int num_count;
	int len;
	int tmp;
	int i, j;
	
	DequeType q;
	scanf("%d", &T);
	scanf("%s", instruct);
	scanf("%d", &n);
	scanf("%s", arr_str);
	
	len = strlen(arr_str);
	for(i=0; i<len; i++) {
		if(arr_str[i]=='[' || arr_str[i]==']')
			continue;
		if(arr_str[i]==',') {
			tmp = 
		}
		if(arr_str[i]>='0' && arr_str[i]<='9') {
			tmp_num[]
		}
	}
	
	for(i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
	
	return 0;	
}