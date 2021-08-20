/**
* 2021. 08. 20
* Creater : Gunhee Choi
* Problem Number : 1912
* Title : 연속합

* Problem :
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.

예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

* Input :
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

	10
	10 -4 3 1 5 6 -35 12 21 -1

* Output :
첫째 줄에 답을 출력한다.

	33

**/

#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a)>=(b)?(a):(b)

int main(void) {
	int N;
	int * arr;
	int * dp;
	int result;
	int i;
	
	scanf("%d", &N);
	arr = (int *) malloc(sizeof(int)*N);
	dp = (int *) malloc(sizeof(int)*N);
	
	for(i=0;i<N; i++)
		scanf("%d", &arr[i]);
	
	dp[0] = arr[0];
	result = arr[0];
	for(i=1; i<N; i++) {
		dp[i] = max(arr[i], arr[i]+dp[i-1]);
		result = max(result, dp[i]);
	}
	
	printf("%d\n", result);
	
	return 0;
}