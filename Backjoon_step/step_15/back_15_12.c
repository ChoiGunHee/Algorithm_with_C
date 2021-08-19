/**
* 2021. 08. 19
* Creater : Gunhee Choi
* Problem Number : 11054
* Title : 가장 긴 바이토닉 부분 수열

* Problem :
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.

예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.

수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 수열 A의 크기 N이 주어지고, 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)

	10
	1 5 2 1 4 3 4 5 2 1

* Output :
첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.

	7

**/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a)>=(b)?(a):(b)

int main(void) {
	int N;
	int arr[1001];
	int dp[1001];
	int r_dp[1001];
	int result=1;
	int i, j;
	
	scanf("%d", &N);
	for(i=1; i<=N; i++)
		scanf("%d", &arr[i]);
	
	for(i=1; i<=N; i++) {
		dp[i]=1;
		for(j=1; j<i; j++)
			if(arr[i]>arr[j])
				dp[i]=max(dp[i], dp[j]+1);
	}
	
	for(i=N; i>=1; i--) {
		r_dp[i]=1;
		for(j=N; j>i; j--)
			if(arr[i]>arr[j])
				r_dp[i]=max(r_dp[i], r_dp[j]+1);
	}
	
	for(i=1; i<=N; i++)
		if(result < (dp[i]+r_dp[i]))
			result = dp[i]+r_dp[i];
	
	printf("%d\n", result-1);
	
	return 0;
}