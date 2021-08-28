/**
* 2021. 08. 26
* Creater : Gunhee Choi
* Problem Number : 11444
* Title : 피보나치 수 3

* Problem :
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

	1000
	
* Output :
첫째 줄에 n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력한다.

	228875

**/

#include <stdio.h>
#define MAX_N 2
#define MOD 1000000


void mul_matrix(long long X[MAX_N][MAX_N], long long Y[MAX_N][MAX_N], int N) {
	long long tmp[MAX_N][MAX_N];
	int i, j, t;
	
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			tmp[i][j] = 0;
			for(t=0; t<N; t++)
				tmp[i][j] += X[i][t]*Y[t][j];
			tmp[i][j] %= MOD;
		}
	}
	
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			X[i][j]=tmp[i][j];
}
/*
void print_matrix(long long m[2][2]) {
	long long i, j;
	for(i=0; i<2; i++) {
		for(j=0; j<2; j++)
			printf("%lld ", m[i][j]);
		printf("\n");
	}
}
*/
int main(void) {
	long long n;
	long long fn[2][2] = {{1,1},{1,0}};
	long long result[2][2] = {{1,0}, {0,1}};
	
	scanf("%lld", &n);
	
	while(n>0) {
		if(n%2==1)
			mul_matrix(result, fn, MAX_N);
		mul_matrix(fn, fn, MAX_N);
		n/=2;
	}
	
	printf("%lld\n", result[0][1]);
	
	return 0;	
}