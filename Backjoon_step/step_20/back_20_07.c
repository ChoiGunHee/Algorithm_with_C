/**
* 2021. 08. 25
* Creater : Gunhee Choi
* Problem Number : 10830
* Title : 행렬 제곱

* Problem :
크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

* Input :
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

	2 5
	1 2
	3 4
	
* Output :
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

	69 558
	337 406

**/

#include <stdio.h>
#define MAX_N 5

long long result[MAX_NUM][MAX_NUM];

/*
void mul_matrix(long long X[MAX_N][MAX_N], long long Y[MAX_N][MAX_N], int N) {
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			for(t=0; t<N; t++) {
				result[i][j] += X[i][t]*Y[t][j];
			}
		}
	}
}
*/
int main(void) {
	
	return 0;	
}