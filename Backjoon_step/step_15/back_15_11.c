/**
* 2021. 08. 19
* Creater : Gunhee Choi
* Problem Number : 11053
* Title : 가장 긴 증가하는 부분 수열

* Problem :
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

* Input :
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

	6
	10 20 10 30 20 50

* Output :
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

	4

**/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a)>=(b)?(a):(b)

int main(void) {
	int N;
	int arr[1001];
	int dp[1001];
	int result = 1;
	int i, j;
	
	scanf("%d", &N);
	for(i=1; i<=N; i++)
		scanf("%d", &arr[i]);
	
	for(i=0; i<=N; i++)
		dp[i] = 1;
	
	for(i=1; i<=N; i++) {
		for(j=1; j<=i; j++)
			if(arr[i]>arr[j])
				dp[i]=max(dp[i], dp[j]+1);
	
		result=max(result, dp[i]);
	}
	
	printf("%d\n", result);
	return 0;
}