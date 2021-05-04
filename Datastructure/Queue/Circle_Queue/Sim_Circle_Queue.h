/* 2021. 05. 04
 * Creater : Gunhee Choi
 * This file is Circle Queue Simulation header
 */

#ifndef SIM_CIRCLE_QUEUE_H
#define SIM_CIRCLE_QUEUE_H
#define MAX_QUEUE_SIZE 5
#define MAX_STRING 100

typedef int element;

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void init_queue(QueueType * queue);
int is_full(QueueType * queue);
int is_empty(QueueType * queue);
int enqueue(QueueType * queue, int data);
int dequeue(QueueType * queue);
void print_queue(QueueType * queue);

#endif