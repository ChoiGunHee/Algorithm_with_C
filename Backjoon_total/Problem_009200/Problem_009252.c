/**
* 2021. 08. 20
* Creater : Gunhee Choi
* Problem Number : 9252
* Title : LCS 2

* Problem :
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

* Input :
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

	ACAYKP
	CAPCAK

* Output :
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를, 둘째 줄에 LCS를 출력한다.

LCS가 여러 가지인 경우에는 아무거나 출력하고, LCS의 길이가 0인 경우에는 둘째 줄을 출력하지 않는다.

	4
	ACAK

**/

#include <stdio.h>
#include <string.h>
#define max(a,b) (a)>=(b)?(a):(b)

int main(void) {
	char str1[1001];
	char str2[1001];
	int dp[1001][1001];
	int str1_len, str2_len;
	int i, j;
	char result[1001];
	int current;
	int count=0;
	
	scanf("%s", str1);
	scanf("%s", str2);
	str1_len = strlen(str1);
	str2_len = strlen(str2);
	
	memset(dp, 0, sizeof(dp));
	
	for(i=1; i<=str1_len; i++) {
		for(j=1; j<=str2_len; j++) {
			if(str1[i-1]==str2[j-1])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	i = str1_len;
	j = str2_len;
	while(i>=1 && j>=1) {
		if(dp[i][j] == dp[i-1][j]) {
			i--;
		} else if (dp[i][j] == dp[i][j-1]) {
			j--;
		}
		else {
			result[count++]=str1[i-1];
			i--;
			j--;
		}
	}
	
	printf("%d\n", dp[str1_len][str2_len]);
	if(count!=0) {
		for(i=count-1; i>=0; i--)
			printf("%c", result[i]);
		printf("\n");
	}

	return 0;
}