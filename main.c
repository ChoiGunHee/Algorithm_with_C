/* 2021. 01. 16
 * Creater : Gunhee Choi
 * This file is Alogrithm Main File
 */

#include "basic.h"
#include "Sim_Stack.h"

int main()
{
	struct Node * head;
	
	printf("Hello World!\n");
	
	init_linked_list(head);
	printf("%d\n", head->data);
	append_liked_list(head, 5);
	append_liked_list(head, 4);
	append_liked_list(head, 3);
	append_liked_list(head, 2);
	append_liked_list(head, 1);
	
	print_linked_list_datas(head);
	
	return 0;
}