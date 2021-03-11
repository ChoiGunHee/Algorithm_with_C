/* 2021. 03. 02
 * Creater : Gunhee Choi
 * This file is Queue Simulation
 */

#include "Sim_Queue.h"

void init_queue(QueueType * queue) {
	queue->rear = -1;
	queue->front = -1;
}

int is_full(QueueType * queue) {
	if(queue->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	
	return 0;
}

int is_empty(QueueType * queue) {
	if(queue->front == queue->rear)
		return 1;
	
	return 0;
}

int enqueue(QueueType * queue, int data) {
	if( is_full(queue) ) {
		printf("Queue is Full\n");
		return -1;
	}
	
	queue->data[++(queue->rear)] = data;
	return 0;
}

int dequeue(QueueType * queue) {
	int data;
	
	if( is_empty(queue) ) {
		printf("Queue is empty\n");
		return -1;
	}
	
	data = queue->data[++(queue->front)];
	return data;
}

void print_queue(QueueType * queue) {
	int i;
	
	for(i=0; i<MAX_QUEUE_SIZE; i++) {
		if(i <= queue->front || i> queue->rear)
			printf("  |  ");
		else
			printf("%d | ", queue->data[i]);
	}
	printf("\n");
}