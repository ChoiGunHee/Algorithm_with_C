/**
* 2021. 05. 08
* Creater : Gunhee Choi
* Problem Number : 10816
* Title : 숫자 카드 2

* Problem :
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

	10
	6 3 2 10 10 10 -10 -10 7 3
	8
	10 9 -5 2 3 4 5 -10

* Output :
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.

	3 0 0 1 2 0 0 2

**/

#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int lower_binary(int * arr, int target, int size) {
    int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start){
        mid = (start + end) / 2;
        if (arr[mid] >= target)
            end = mid;
        else start = mid + 1;
    }
	
    return end;
}
 
int upper_binary(int * arr, int target, int size) {
    int mid, start, end;
    start = 0, end = size - 1;
 
    while (end > start) {
        mid = (start + end) / 2;
        if (arr[mid] > target)
            end = mid;
        else start = mid + 1;
    }
	
    return end;
}


int main(void) {
	int N, M;
	int * arr_N;
	int * arr_M;
	int upper, lower;
	int i;
	
	scanf("%d", &N);
	arr_N = (int *) malloc(sizeof(int) * N);
	for(i=0; i<N; i++)
		scanf("%d", &arr_N[i]);
	
	scanf("%d", &M);
	arr_M = (int *) malloc(sizeof(int) * M);
	for(i=0; i<M; i++)
		scanf("%d", &arr_M[i]);
	
	qsort(arr_N, N, sizeof(int), compare);
	
	for(i=0; i<M; i++) {
		upper = upper_binary(arr_N, arr_M[i], N);
		lower = lower_binary(arr_N, arr_M[i], N);
		
		if(upper == N - 1 && arr_N[N - 1] == arr_M[i]) upper++;
		
		printf("%d ",  upper - lower);
	}
	
	printf("\n");
	
	return 0;	
}