/**
* 2021. 09. 04
* Creater : Gunhee Choi
* Problem Number : 2440
* Title : 별 찍기 - 3

* Problem :
첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제

* Input :
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

	5

* Output :
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

	*****
	****
	***
	**
	*

**/

#include <stdio.h>

int main(void) {
	int n;
	int i,j;
	
	scanf("%d", &n);
	for(i=n; i>0; i--) {
		for(j=i; j>0; j--)
			printf("*");
		printf("\n");
	}
	
	return 0;	
}