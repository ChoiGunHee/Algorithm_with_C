#include "basic.h"
#include "Sim_Deque.h"

int main(void) {
	DequeType q;
	int i;
	
	printf("Hello World!\n in Deque!!\n");
	
	init_queue(&q);
	
	for(i=0; i<3; i++) {
		add_front(&q, i);
		deque_print(&q);
	}
	
	for(i=0; i<3; i++) {
		delete_rear(&q);
		deque_print(&q);
	}
	
	return 0;
}