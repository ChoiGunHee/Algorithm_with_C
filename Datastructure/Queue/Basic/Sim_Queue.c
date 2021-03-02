/* 2021. 03. 02
 * Creater : Gunhee Choi
 * This file is Queue Simulation
 */

void init_stack(QueueType * queue) {
	q->rear = -1;
	q->front = -1;
}
int is_full(QueueType * queue);
int is_empty(QueueType * queue);
int enqueue(QueueType * queue);
int dequeue(QueueType * queue);