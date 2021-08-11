/**
* 2021. 08. 11
* Creater : Gunhee Choi
* Problem Number : 1992
* Title : N-Queen

* Problem :
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

	8

* Output :
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

	92

**/

#include <stdio.h>
#include <stdlib.h>

int N;
int result;
int lct[15];

int check(int q) {
	int i;
	
	//경로 판단(같은 열 판단, 대각선 판단(열의차이와 행의 차이가 같으면 대각선상에 있음))
	for(i=0; i<q; i++)
		if((lct[q]==lct[i]) || ((q-i)==abs(lct[q]-lct[i])))
			return 0;
	
	return 1;
}

void count_queen(int s_lct) {
	int i, j;
	int flag = 1;
	
	if(s_lct == N) {
		result++;
		return;
	}
	
	for(i=0; i<N; i++) {
		lct[s_lct] = i;
		/*
		for(j=0; j<s_lct; j++)
			if(lct[s_lct]==lct[j] || (s_lct-j)==abs(lct[s_lct]-lct[j])) {
				flag = 0;
				break;
			}
		*/	
		if(check(s_lct))
			count_queen(s_lct+1);
	}
}

int main(void) {
	scanf("%d", &N);

	count_queen(0);
	
	printf("%d\n", result);
	
	return 0;	
}
