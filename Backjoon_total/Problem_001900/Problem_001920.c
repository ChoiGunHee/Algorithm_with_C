/**
* 2021. 04. 28
* Creater : Gunhee Choi
* Problem Number : 1920
* Title : 수 찾기 

* Problem :
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

* Input :
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

	5
	4 1 5 2 3
	5
	1 3 7 9 5

* Output :
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

	1
	1
	0
	0
	1

**/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

int main(void) {
	int N, M;
	int * arr_N;
	int min = INT_MAX;
	int max = INT_MIN;
	int i, j, temp;
	int result;
	
	scanf("%d", &N);
	arr_N = (int *) malloc(sizeof(int) * N);
	for(i=0; i<N; i++) {
		scanf("%d", &arr_N[i]);
		
		if(min > arr_N[i]) min = arr_N[i];
		if(max < arr_N[i]) max = arr_N[i];
	}
	
	scanf("%d", &M);
	
	for(i=0; i<M; i++) {
		result = 0;
		scanf("%d", &temp);
		if(temp >= min)
		
		if(temp <= max && temp >= min) {
			for(j=0; j<N; j++) {
				if(temp == arr_N[j]) {
					result = 1;
					break;
				}
			}//end of j

		}
		printf("%d\n", result);
	}// end of i
	
	return 0;	
}