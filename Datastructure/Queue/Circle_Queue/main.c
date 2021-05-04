#include "basic.h"
#include "Sim_Circle_Queue.h"

int main(void) {
	int data = 0;
	QueueType q;
	
	printf("Hello World!\n in Queue!!\n");
	
	init_queue(&q);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	enqueue(&q, 40);
	enqueue(&q, 50);
	print_queue(&q);
	
	data = dequeue(&q);
	data = dequeue(&q);
	enqueue(&q, 10);
	print_queue(&q);
	
	return 0;
}