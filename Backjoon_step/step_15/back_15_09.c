/**
* 2021. 08. 01
* Creater : Gunhee Choi
* Problem Number : 10844
* Title : 쉬운 계단 수

* Problem :
45656이란 수를 보자.
이 수는 인접한 모든 자리수의 차이가 1이 난다. 이런 수를 계단 수라고 한다.
세준이는 수의 길이가 N인 계단 수가 몇 개 있는지 궁금해졌다.
N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구하는 프로그램을 작성하시오. (0으로 시작하는 수는 없다.)

* Input :
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

	2

* Output :
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

	17

**/

#include <stdio.h>
#define MAX_NUM 101
#define MOD 1000000000

int main(void) {
	int N;
	long long dp[MAX_NUM][11];
	long long result = 0;
	int i, j;
	
	scanf("%d", &N);
	
	dp[1][0] = 0;
	for(i=1; i<=9; i++)
		dp[1][i] = 1;
	
	for(i=2; i<=N; i++) {
		for(j=0; j<=9; j++) {
			if(j==0)
				dp[i][j] = dp[i-1][j+1] % MOD;
			else if(j==9)
				dp[i][j] = dp[i-1][j-1] % MOD;
			else
				dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1]) % MOD;
		}
	}
	
	for(i=0; i<=9; i++)
		result += dp[N][i];
	
	printf("%lld\n", result%MOD);
	
	return 0;
}