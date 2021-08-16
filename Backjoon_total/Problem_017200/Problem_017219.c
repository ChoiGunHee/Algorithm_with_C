/**
* 2021. 08. 15
* Creater : Gunhee Choi
* Problem Number : 17219
* Title : 비밀번호 찾기

* Problem :
2019 HEPC - MAVEN League의 "비밀번호 만들기"와 같은 방식으로 비밀번호를 만든 경민이는 한 가지 문제점을 발견하였다. 비밀번호가 랜덤으로 만들어져서 기억을 못 한다는 것이었다! 그래서 경민이는 메모장에 사이트의 주소와 비밀번호를 저장해두기로 했다. 하지만 컴맹인 경민이는 메모장에서 찾기 기능을 활용하지 못하고 직접 눈으로 사이트의 주소와 비밀번호를 찾았다. 메모장에 저장된 사이트의 수가 늘어나면서 경민이는 비밀번호를 찾는 일에 시간을 너무 많이 쓰게 되었다. 이를 딱하게 여긴 문석이는 경민이를 위해 메모장에서 비밀번호를 찾는 프로그램을 만들기로 결심하였다! 문석이를 도와 경민이의 메모장에서 비밀번호를 찾아주는 프로그램을 만들어보자.

* Input :
첫째 줄에 저장된 사이트 주소의 수 N(1 ≤ N ≤ 100,000)과 비밀번호를 찾으려는 사이트 주소의 수 M(1 ≤ M ≤ 100,000)이 주어진다.

두번째 줄부터 N개의 줄에 걸쳐 각 줄에 사이트 주소와 비밀번호가 공백으로 구분되어 주어진다. 사이트 주소는 알파벳 소문자, 알파벳 대문자, 대시('-'), 마침표('.')로 이루어져 있고, 중복되지 않는다. 비밀번호는 알파벳 대문자로만 이루어져 있다. 모두 길이는 최대 20자이다.

N+2번째 줄부터 M개의 줄에 걸쳐 비밀번호를 찾으려는 사이트 주소가 한줄에 하나씩 입력된다. 이때, 반드시 이미 저장된 사이트 주소가 입력된다.

	16 4
	noj.am IU
	acmicpc.net UAENA
	startlink.io THEKINGOD
	google.com ZEZE
	nate.com VOICEMAIL
	naver.com REDQUEEN
	daum.net MODERNTIMES
	utube.com BLACKOUT
	zum.com LASTFANTASY
	dreamwiz.com RAINDROP
	hanyang.ac.kr SOMEDAY
	dhlottery.co.kr BOO
	duksoo.hs.kr HAVANA
	hanyang-u.ms.kr OBLIVIATE
	yd.es.kr LOVEATTACK
	mcc.hanyang.ac.kr ADREAMER
	startlink.io
	acmicpc.net
	noj.am
	mcc.hanyang.ac.kr
	
* Output :
첫 번째 줄부터 M개의 줄에 걸쳐 비밀번호를 찾으려는 사이트 주소의 비밀번호를 차례대로 각 줄에 하나씩 출력한다.

	THEKINGOD
	UAENA
	IU
	ADREAMER

**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 1000001

typedef struct Node {
	int key;
	int num;
	char name[25];
	char password[25];
	int size;
	struct Node * next;	
} Node;

Node site[MAX_NUM];

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
	
	while(strcmp(name, tmp_node->name) != 0) {
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
		key *= (name[i]);
		key++;
		key %= MAX_NUM;
	}
	
	return key;
}


void insert_hash(char * _name, char * _password, int _num) {
	int _key = hash_func(_name);
	Node * tmp_node;

	if(site[_key].size < 1) {
		site[_key].key = _key;
		site[_key].num = _num;
		strcpy(site[_key].name, _name);
		strcpy(site[_key].password, _password);
		site[_key].size = 1;
		
	} else {
		tmp_node = &site[_key];
		tmp_node->size++;
		
		while(tmp_node->next)
			tmp_node = tmp_node->next;
		
		tmp_node->next = create_node(_key, _name, _num);
	}
}

Node * search_hash(char * _name) {
	int _key = hash_func(_name);
	Node * tmp_node = &site[_key];
	
	if(strcmp(_name, tmp_node->name) != 0) {
		tmp_node = search_node(tmp_node, _name);
	}
	
	return tmp_node;
}

int main(void) {
	int N, M;
	Node * tmp_node;
	int _key;
	char _site[25];
	char _password[25];
	int i;
	
	scanf("%d %d", &N, &M);
	for(i=1; i<=N; i++) {
		scanf("%s %s", _site, _password);
		insert_hash(_site, _password, i);
	}
	
	for(i=0; i<M; i++) {
		scanf("%s", _site);
		tmp_node = search_hash(_site);
		printf("%s\n", tmp_node->password);	
	}
	
	return 0;	
}