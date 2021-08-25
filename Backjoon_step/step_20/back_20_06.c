/**
* 2021. 08. 25
* Creater : Gunhee Choi
* Problem Number : 2740
* Title : 행렬 곱셈

* Problem :
N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

* Input :
첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다. 이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

	3 2
	1 2
	3 4
	5 6
	2 3
	-1 -2 0
	0 0 3
	
* Output :
첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.

	-1 -2 6
	-3 -6 12
	-5 -10 18

**/

#include <stdio.h>

int main(void) {
	int NA, MA;
	int MB, KB;
	int A[100][100];
	int B[100][100];
	int result[100][100];
	int t;
	int i, j;
	
	scanf("%d %d",&NA, &MA);
	for(i=0; i<NA; i++)
		for(j=0; j<MA; j++)
			scanf("%d", &A[i][j]);
	
	scanf("%d %d",&MB, &KB);
	for(i=0; i<MB; i++)
		for(j=0; j<KB; j++)
			scanf("%d", &B[i][j]);
	
	for(i=0; i<NA; i++) {
		for(j=0; j<KB; j++) {
			for(t=0; t<MA; t++) {
				result[i][j] += A[i][t]*B[t][j];
			}
		}
	}
	
	for(i=0; i<NA; i++) {
		for(j=0; j<KB; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	return 0;	
}