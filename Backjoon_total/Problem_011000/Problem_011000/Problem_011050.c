/**
* 2021. 05. 01
* Creater : Gunhee Choi
* Problem Number : 11050
* Title : 이항 계수

* Problem :
자연수 과 정수 가 주어졌을 때 이항 계수 (N K)를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N과 가 K주어진다. (1 ≤ N  ≤ 10, 0 ≤ K  ≤  N )

	5 2

* Output :
(N K)를 출력한다.

	10

**/

#include <stdio.h>

int main(void) {
	int N, K;
	int up=1, down=1;
	int t_k = 1, t_nk = 1;
	int i;
	
	scanf("%d %d", &N, &K);
	if(K == 0 || K == N) {
		printf("1\n");
		return 0;
	}
	
	for(i=1; i<=N; i++)
		up *= i;
	
	for(i=1; i<=K; i++)
		t_k *= i;
	
	for(i=1; i<=N-K; i++)
		t_nk *= i;
	
	down = t_k * t_nk;
	printf("%d\n", up/down);
	
	return 0;	
}