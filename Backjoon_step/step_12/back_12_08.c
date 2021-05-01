/**
* 2021. 05. 01
* Creater : Gunhee Choi
* Problem Number : 1181
* Title : 단어 정렬

* Problem :
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

	- 길이가 짧은 것부터
	- 길이가 같으면 사전 순으로

* Input :
첫째 줄에 단어의 개수 N이 주어진다. (1 ≤ N ≤ 20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

	13
	but
	i
	wont
	hesitate
	no
	more
	no
	more
	it
	cannot
	wait
	im
	yours

* Output :
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.

	i
	im
	it
	no
	but
	more
	wait
	wont
	yours
	cannot
	hesitate

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARR 20000
#define MAX_STR 100

typedef struct word {
	char str[100];
	int len;
} Word;


int compare(const void * a, const void * b)
{
    struct word * word1 = (struct word *) a;
    struct word * word2 = (struct word *) b;

    if(word1->len > word2->len) return 1;
	else if(word1->len < word2->len) return -1;
	else return strcmp(word1->str, word2->str);
	
    return 0;
}

int main(void) {
	int N;
	struct word list[MAX_ARR];
	char buffer[MAX_STR];
	int t_len;
	int flag = 0;
	int i, j;
	
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		scanf("%s", buffer);
		for(j=0; j<i; j++) {
			if(strcmp(buffer, list[j].str) == 0) {
				flag = 1;
				break;
			}
		}
		
		if(flag == 1) {
			flag = 0;
			continue;
		} else {
			strcpy(list[i].str, buffer);
			list[i].len = strlen(buffer);
		}
	}
	
	qsort(list, N, sizeof(Word), compare);
	
	for(i=0; i<N; i++)
		printf("%s\n", list[i].str);
	
	return 0;	
}