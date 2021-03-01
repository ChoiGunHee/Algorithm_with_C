#include "../Basic/basic.h"
#include "../Basic/Sim_Stack.h"

int main(void) {
	printf("Hello World!\n in Stack!!\n");
	
	StackType stack;
	init_stack(&stack);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 5);
	
	printf("%d \n", pop(&stack));
	printf("%d \n", pop(&stack));
	printf("%d \n", pop(&stack));
	
	free(stack.data);
	
	return 0;
}