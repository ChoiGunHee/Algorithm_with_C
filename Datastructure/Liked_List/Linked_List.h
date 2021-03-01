/* 2021. 01. 17
 * Creater : Gunhee Choi
 * This file is Linked List header
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "basic.h"

typedef struct NODE  {
	int data;
	struct NODE * next;
} NODE;

//Test Function
void linked_list_Test_function();

NODE * init_linked_list(NODE * node);
NODE * init_linked_list_test(NODE * node);
int append_liked_list(NODE * head, int data);
int delet_liked_list();
int search_data();
int print_linked_list_datas(NODE * head);

#endif