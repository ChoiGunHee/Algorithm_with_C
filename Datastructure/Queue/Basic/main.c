#include "basic.h"
#include "Sim_Queue.h"

int main(void) {
	int data = 0;
	QueueType q;
	
	printf("Hello World!\n in Queue!!\n");
	
	init_queue(&q);
	
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	print_queue(&q);
	
	data =dequeue(&q);
	data =dequeue(&q);
	print_queue(&q);
	
	return 0;
}