/**
* 2021. 07. 25
* Creater : Gunhee Choi
* Problem Number : 11051
* Title : 이항 계수 2

* Problem :
자연수 과 정수 가 주어졌을 때 이항 계수를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 과 가 주어진다. (1 ≤  ≤ 1,000, 0 ≤  ≤ )

	5 2

* Output :
(N K)를 출력한다.

	10

**/

#include <stdio.h>
#define M_NUM 10007

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
	
	for(i=1; i<=N; i++) {
		up *= i;
		up %= M_NUM;
	}
		
	
	for(i=1; i<=K; i++) {
		t_k *= i;
		t_k %= M_NUM;
	}
		
	
	for(i=1; i<=N-K; i++) {
		t_nk *= i;
		t_nk %= M_NUM;
	}
		
	
	down = t_k * t_nk;
	printf("%d\n", (up/down)%M_NUM);
	
	return 0;	
}