/* 2021. 01. 17
 * Creater : Gunhee Choi
 * This file is Linked List
 */

#include "Linked_List.h"

int init_linked_list(struct NODE * head)
{
	head = malloc(sizeof(struct NODE));
	head->data = 3;
	head->next = NULL;
	
	printf("Sucess init Linked List!\n");
	
	return 0;
}

int append_liked_list(struct NODE * head, int data)
{
	struct NODE * temp_node;
	struct NODE * data_node;
	
	temp_node = head;
	
	while(temp_node->next != NULL){
		printf("0\n");
		temp_node = temp_node->next;
	}
		
	
	
	data_node = malloc(sizeof(struct NODE));
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

int print_linked_list_datas(struct NODE * head)
{
	int i;
	struct NODE * temp_node = head;
	
	printf("Print Linked List Datas!\n");
	for( ; temp_node->next; )
	{
		printf("data %d : %d", i, temp_node->data);
		temp_node = temp_node->next;
	}
	
	return 0;	
}