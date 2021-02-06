/**
* 2021. 01. 18
* Creater : Gunhee Choi
* Problem Number : 10818
* Title : 최소, 최대

* Problem :
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.
	5
	20 10 35 30 7
	
* Output : 첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.
	7 35

**/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int * arr;
	int i, n;
	int min, max;
	
	scanf("%d", &n);
	
	arr =(int *) malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	
	min = arr[0];
	max = arr[0];
	for(i=0; i<n; i++) {
		if(arr[i] < min)
			min = arr[i];
		if(arr[i] > max)
			max = arr[i];
	}
	
	printf("%d %d\n", min, max);
	
	return 0;
}