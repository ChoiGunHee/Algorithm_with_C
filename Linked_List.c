/* 2021. 01. 17
 * Creater : Gunhee Choi
 * This file is Linked List
 */

#include "Linked_List.h"

//Test Function
void linked_list_Test_function()
{
	//Init Linked List Head
	NODE * head = (NODE * ) malloc(sizeof(NODE));
	printf("Hello World!\n");
	
	init_linked_list_test(head);
	
	append_liked_list(head, 5);
	append_liked_list(head, 4);
	append_liked_list(head, 3);
	append_liked_list(head, 2);
	append_liked_list(head, 1);
	
	print_linked_list_datas(head);
}

NODE * init_linked_list(NODE * node)
{
	
	NODE * temp_node = (NODE * ) malloc(sizeof(NODE));
	temp_node->data = 100;
	temp_node->next = NULL;
	
	node = temp_node;
	
	printf("init : %d\n", node->data);
	printf("Sucess init Linked List!\n");
	
	return node;
}

NODE * init_linked_list_test(NODE * node)
{
	node->data = 100;
	node->next = NULL;
	
	printf("init : %d\n", node->data);
	printf("Sucess init Linked List!\n");
	
	return node;
}

int append_liked_list(NODE * head, int data)
{
	NODE * temp_node;
	NODE * data_node;
	
	temp_node = head;
	
	while(temp_node->next != NULL){
		temp_node = temp_node->next;
	}
		
	data_node = (NODE *) malloc(sizeof(NODE));
	data_node->data = data;
	data_node->next = NULL;
	temp_node->next = data_node;
	
	printf("Sucess Append Linked List! ( data : %d )\n", data);
	
	return 0;
}

int delet_liked_list()
{
	printf("Test\n");
	return 0;
}

int search_data()
{
	printf("Test\n");
	return 0;	
}

int print_linked_list_datas(NODE * head)
{
	int i = 0;
	NODE * temp_node = head->next;
	
	printf("Print Linked List Datas!\n");
	printf("data : ");
	while(temp_node != NULL)
	{
		printf("%d ", temp_node->data);
		temp_node = temp_node->next;
		i++;
	}
	
	return 0;	
}