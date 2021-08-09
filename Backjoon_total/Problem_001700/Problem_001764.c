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

char namelist[MAX_NUM][25];
char results[MAX_NUM][25];

int compare(const void * a, const void * b)
{
	char * str1 = (char *) a;
	char * str2 = (char *) b;
	
	int result = strcmp(str1, str2);
	
	if(result < 0) return -1;
	else if(result > 0) return 1;

    return result;
}

int binary_search(char * name, int low, int high) {
	int mid;
	int tmp;
	
	while (low <= high) {
		mid = (low + high) / 2;
		tmp = strcmp(name, namelist[mid]);
		if(!tmp) return mid;
		else if(tmp>0) low = mid + 1;
		else high = mid - 1;
	}
	
	return -1;
}

int main(void) {
	int N, M;
	char _name[25];
	int count=0;
	int tmp;
	int i;
	
	scanf("%d %d", &N, &M);
	for(i=0; i<N; i++)
		scanf("%s", namelist[i]);
	
	qsort(namelist, N, 25, compare);
	
	for(i=0; i<N; i++) {
		scanf("%s", _name);
		tmp = binary_search(_name, 0, N);
		if(tmp!=-1) {
			strcpy(results[count], namelist[tmp]);
			count++;
		}
	}
	
	qsort(results, count, 25, compare);
	
	printf("%d\n", count);
	for(i=0; i<count; i++)
		printf("%s\n", results[i]);
	
	return 0;	
}