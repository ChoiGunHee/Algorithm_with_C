/* 2021. 05. 04
 * Creater : Gunhee Choi
 * This file is Circle Queue Simulation header
 */

#include "Sim_Circle_Queue.h"
#include "basic.h"

void init_queue(QueueType * queue) {
	queue->rear = queue->front = 0;
}

int is_full(QueueType * queue) {
	return  ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front);
}

int is_empty(QueueType * queue) {
	return (queue->front == queue->rear);
}

int enqueue(QueueType * queue, element data) {
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