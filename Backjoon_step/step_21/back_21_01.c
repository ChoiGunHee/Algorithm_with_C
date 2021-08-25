/**
* 2021. 08. 25
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

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int binary_search(int list[], int key, int low, int high) {
	int mid;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if(key == list[mid]) return mid;
		else if(key > list[mid]) low = mid + 1;
		else high = mid - 1;
	}
	
	return -1;
}

int main(void) {
	int N, M;
	int * arr_N;
	int * arr_M;
	int i, t;
	int result;
	
	scanf("%d", &N);
	arr_N = (int *) malloc(sizeof(int) * N);
	for(i=0; i<N; i++)
		scanf("%d", &arr_N[i]);
	
	qsort(arr_N, N, sizeof(int), compare);
	
	
	scanf("%d", &M);
	arr_M = (int *) malloc(sizeof(int) * M);
	for(i=0; i<M; i++) {
		scanf("%d", &t);
		arr_M[i] = binary_search(arr_N, t, 0, N-1);
	}
	
	for(i=0; i<M; i++) {
		if(arr_M[i] == -1) printf("0\n");
		else printf("1\n");
	}
	
	return 0;	
}