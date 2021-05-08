/**
* 2021. 05. 08
* Creater : Gunhee Choi
* Problem Number : 10866
* Title : 덱

* Problem :
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

* Input :
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

	15
	push_back 1
	push_front 2
	front
	back
	size
	empty
	pop_front
	pop_back
	pop_front
	size
	empty
	pop_back
	push_front 3
	empty
	front

* Output :
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

	2
	1
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
#define MAX_QUEUE_SIZE 10000

typedef int element;

typedef struct {
	int front;
	int rear;
	int data_size;
	element data[MAX_QUEUE_SIZE];
} DequeType;

void init_queue(DequeType * queue) {
	queue->rear = queue->front = 0;
	queue->data_size = 0;
}

int is_full(DequeType * queue) {
	return  ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

int is_empty(DequeType * queue) {
	return (queue->front == queue->rear);
}

int is_size(DequeType * queue) {
	return queue->data_size;
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
	
	q->data_size++;
	q->data[q->front] = item;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_front(DequeType * q) {
	if(is_empty(q)) return -1;
	
	q->data_size--;
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType * q) {
	if(is_empty(q)) return -1;
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_rear(DequeType * q, element item) {
	if(is_full(q)) 
		printf("Queue is Full\n");
	
	q->data_size++;
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_rear(DequeType * q) {
	int prev = q->rear;
	if(is_empty(q)) return -1;
	
	q->data_size--;
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType * q) {
	if(is_empty(q)) return -1;
	return q->data[q->rear];
}

int main(void) {
	int N;
	char p_str[20];
	int temp;
	int i;
	
	DequeType q;
	init_queue(&q);
	
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		scanf("%s", p_str);

		if( strcmp("push_front", p_str) == 0 ) {
			scanf("%d", &temp);
			add_front(&q, temp);
		} else if( strcmp("push_back", p_str) == 0 ) {
			scanf("%d", &temp);
			add_rear(&q, temp);
		} else if( strcmp("pop_front", p_str) == 0 ) {
			printf("%d\n", delete_front(&q));
		} else if( strcmp("pop_back", p_str) == 0 ) {
			printf("%d\n", delete_rear(&q));
		} else if( strcmp("empty", p_str) == 0 ) {
			printf("%d\n", is_empty(&q));
		} else if( strcmp("front", p_str) == 0 ) {
			printf("%d\n", get_front(&q));
		} else if( strcmp("back", p_str) == 0 ) {
			printf("%d\n", get_rear(&q));
		} else if( strcmp("size", p_str) == 0 ) {
			printf("%d\n", is_size(&q));
		}
	}
	
	return 0;	
}