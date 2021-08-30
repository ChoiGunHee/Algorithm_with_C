/**
* 2021. 05. 05
* Creater : Gunhee Choi
* Problem Number : 10866
* Title : 요세푸스 문제 0

* Problem :
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N과 K가 빈 칸을 사이에 두고 순서대로 주어진다. (1 ≤ K ≤ N ≤ 1,000)

	7 3

* Output :
예제와 같이 요세푸스 순열을 출력한다.

	<3, 6, 2, 7, 5, 1, 4>

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_QUEUE_SIZE = 0;

typedef struct {
	int front;
	int rear;
	int * data;
} QueueType;

void init_queue(QueueType * queue, int size) {
	queue->rear = queue->front = 0;
	queue->data = (int *) malloc(sizeof(int) * size);
	MAX_QUEUE_SIZE = size;
}

int is_full(QueueType * queue) {
	return  ( ((queue->rear + 1) % MAX_QUEUE_SIZE) == queue->front);
}

int is_empty(QueueType * queue) {
	return (queue->front == queue->rear);
}

int enqueue(QueueType * queue, int data) {
	if( is_full(queue) ) {
		printf("Queue is Full\n");
		return -1;
	}
	queue->rear = (queue->rear +1) % MAX_QUEUE_SIZE;
	queue->data[queue->rear] = data;
	return 0;
}

int dequeue(QueueType * queue) {
	if(is_empty(queue)) printf("Queue is empty");
	queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
	return queue->data[queue->front];
}

void print_queue(QueueType * queue) {
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

int is_size(QueueType * queue) {
	
}

int main(void) {
	int N, K;
	QueueType q;
	int * result;
	int i, count, t;
	
	scanf("%d %d", &N, &K);
	result = (int *) malloc(sizeof(int) * N);
	
	init_queue(&q, N + 1);
	
	for(i=1; i<=N; i++)
		enqueue(&q, i);
	
	for(count = 0; count<N; count++) {
		for(i=0; i<K-1; i++) {
			t = dequeue(&q);
			enqueue(&q, t);
		}
		
		result[count] = dequeue(&q);
	}
	
	printf("<");
	for(i=0; i<N-1; i++) printf("%d, ", result[i]);
	printf("%d>\n", result[i]);
		
	
	return 0;	
}