/**
* 2021. 08. 08
* Creater : Gunhee Choi
* Problem Number : 1764
* Title : 듣보잡

* Problem :
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 영어 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.

듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

	3 4
	ohhenrie
	charlie
	baesangwook
	obama
	baesangwook
	ohhenrie
	clinton
	
* Output :
듣보잡의 수와 그 명단을 사전순으로 출력한다.

	2
	baesangwook
	ohhenrie

**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 500001

typedef struct Node {
	int key;
	int num;
	char name[25];
	int size;
	struct Node * next;	
} Node;

typedef struct word {
	char str[25];
	int len;
} Word;

Node person_list[MAX_NUM];
Word results[MAX_NUM];

int compare(const void * a, const void * b)
{
    struct word * word1 = (struct word *) a;
    struct word * word2 = (struct word *) b;
	
	if(strcmp(word1->str, word2->str) < 0) return -1;
	else if(strcmp(word1->str, word2->str) > 0) return 1;
	
    return 0;
}

void insert_Node(Node * head, int _key, char * _name) {
	Node * pre_node;
	Node * _node = (Node *) malloc(sizeof(Node));
	
	_node->key = _key;
	strcpy(_node->name, _name);
	
	pre_node = head;
	while(pre_node->next) {
		pre_node = pre_node->next;
	}
	
	pre_node->next = _node;
	
	return;
}

Node * create_node(int _key, char * name, int _num) {
	Node * node = (Node *) malloc(sizeof(Node));
	node->key = _key;
	node->num = _num;
	strcpy(node->name, name);
	node->next = 0;
	node->size = 1;
	
	return node;
}

Node * search_node(Node * head, char * name) {
	Node * tmp_node = head;
	
	while(tmp_node->next) {
		if(strcmp(name, tmp_node->name)!= 0)
			tmp_node = tmp_node->next;
	}
	
	return tmp_node;
}

void printNodeList(Node * head) {
	Node * current = head;

	while(current) {
		printf("Key : %d, Name : %s\n", current->key, current->name);
		current = current->next;
	}
}

int hash_func(char * name) {
	int key = 0;
	int i;

	for(i=0; i<strlen(name); i++) {
		key *= (name[i]-'a');
		key %= MAX_NUM;
		key++;
	}
	
	return key;
}


void insert_hash(char * _name, int _num) {
	int _key = hash_func(_name);
	Node * tmp_node;
	
	if(person_list[_key].size < 1) {
		person_list[_key].key = _key;
		person_list[_key].num = _num;
		strcpy(person_list[_key].name, _name);
	} else {
		tmp_node = &person_list[_key];
		tmp_node->size++;
		
		while(tmp_node->next)
			tmp_node = tmp_node->next;
		
		tmp_node->next = create_node(_key, _name, _num);
	}
}

Node * search_hash(char * _name) {
	int _key = hash_func(_name);
	Node * tmp_node = &person_list[_key];
	
	if(strcmp(_name, tmp_node->name) != 0) {
		
		tmp_node = search_node(tmp_node, _name);
	}

	return tmp_node;
}

int main(void) {
	int N, M;
	Node * tmp_node;
	int _key;
	char _name[25];
	int count=0;
	int i;
	
	scanf("%d %d", &N, &M);
	for(i=0; i<N; i++) {
		scanf("%s", _name);
		insert_hash(_name, i);
	}
	
	for(i=0; i<M; i++) {
		scanf("%s", _name);
		tmp_node = search_hash(_name);
		
		if(tmp_node->key != 0 && strcmp(tmp_node->name, _name)==0) {
			strcpy(results[count].str, _name);
			results[count].len = strlen(_name);
			count++;
		}
	}

	qsort(results, count, sizeof(Word), compare);

	printf("%d\n", count);
	
	for(i=0; i<count; i++)
		printf("%s\n", results[i].str);

	return 0;	
}