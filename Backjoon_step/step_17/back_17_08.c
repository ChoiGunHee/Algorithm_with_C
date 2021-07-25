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

long long dp[1001][1001];

int main(void) {
	int N, K;
	int i, j;
	
	scanf("%d %d", &N, &K);
	
	for(i=1; i<=N; i++) {
		for(j=0; j<=K; j++) {
			if(i==j || j==0)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % M_NUM;
		}
	}
	
	printf("%lld\n", dp[N][K]);
	
	return 0;	
}