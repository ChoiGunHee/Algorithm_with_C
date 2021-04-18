/**
* 2021. 04. 18
* Creater : Gunhee Choi
* Problem Number : 10989
* Title : 수 정렬하기 3

* Problem :
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

* Input : 첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

	10
	5
	2
	3
	1
	4
	2
	3
	5
	1
	7

* Output : 첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

	1
	1
	2
	2
	3
	3
	4
	5
	5
	7

**/

#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 10001

int main(void) {
	int N;
	int num;
	int counting[MAX_NUM] = {0, };
	int i, j;
	
	scanf("%d", &N);
	for(i=0; i<N; i++) {
		scanf("%d", &num);
		counting[num]++;
	}
	
	for(i=0; i<MAX_NUM; i++) {
		for(j=0; j<counting[i]; j++) {
			printf("%d ", i);
		}
	}
	printf("\n");
	
	return 0;	
}