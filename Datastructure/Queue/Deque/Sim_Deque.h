/* 2021. 05. 08
 * Creater : Gunhee Choi
 * This file is Deque Simulation header
 */

#ifndef SIM_DEQUE_H
#define SIM_DEQUE_H
#define MAX_QUEUE_SIZE 5
#define MAX_STRING 100

typedef int element;

typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} DequeType;

void init_queue(DequeType * q);
int is_full(DequeType * q);
int is_empty(DequeType * q);

void add_front(DequeType * q, element item);
element delete_front(DequeType * q);
element get_front(DequeType * q);

void add_rear(DequeType * q, element item);
element delete_rear(DequeType * q);
element get_rear(DequeType * q);

void deque_print(DequeType * q);

#endif