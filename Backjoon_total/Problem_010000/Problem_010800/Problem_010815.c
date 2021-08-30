/**
* 2021. 08. 29
* Creater : Gunhee Choi
* Problem Number : 10815
* Title : 숫자 카드 

* Problem :
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

	5
	6 3 2 10 -10
	8
	10 9 -5 2 3 4 5 -10

* Output :
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.

	1 0 0 1 1 0 0 1

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
		if(arr_M[i] == -1) printf("0 ");
		else printf("1 ");
	}
	printf("\n");
	
	return 0;	
}