/* 2021. 05. 08
 * Creater : Gunhee Choi
 * This file is Deque Simulation
 */

#include "basic.h"
#include "Sim_Deque.h"

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