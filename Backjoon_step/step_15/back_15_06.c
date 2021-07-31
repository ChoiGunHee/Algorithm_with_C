/**
* 2021. 07. 30
* Creater : Gunhee Choi
* Problem Number : 1932
* Title : 정수 삼각형

* Problem :
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

* Input :
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

	5
	7
	3 8
	8 1 0
	2 7 4 4
	4 5 2 6 5
	
* Output :
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다.

	30

**/

#include <stdio.h>
#define MAX_NUM 501
#define max(a,b) (a)>=(b)?(a):(b)

int dp[MAX_NUM][MAX_NUM];

int main(void) {
	int n;
    int i, j;
	int max_value = -1;
	
	scanf("%d", &n);
	
    for(i=1; i<=n; i++)
        for(j=1; j<=i; j++)
            scanf("%d", &dp[i][j]);

    for(i=2; i<=n; i++){
        for(j=1; j<=i; j++){
            if(j==1)
				dp[i][j] += dp[i-1][j];
            else if(j==i)
				dp[i][j] += dp[i-1][j-1];
            else
				dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
        }
    }
	
    for(i=1; i<=n; i++)
        if(max_value<dp[n][i])
			max_value = dp[n][i];
	
	printf("%d\n", max_value);
	
	return 0;	
}