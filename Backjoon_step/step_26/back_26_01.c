/**
* 2021. 08. 22
* Creater : Gunhee Choi
* Problem Number : 3273
* Title : 두수의 합

* Problem :
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1,000,000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2,000,000)

	9
	5 12 7 10 9 1 2 3 11
	13
	
* Output :
문제의 조건을 만족하는 쌍의 개수를 출력한다.

	3

**/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if(num1 < num2)
		return -1;
	else if(num1 > num2)
		return 1;

	return 0;
}

int main(void) {
	int n;
	int * arr;
	int x;
	int start, end;
	int sum;
	int result;
	int i;
	
	scanf("%d", &n);
	arr = (int*) malloc(sizeof(int)*n);
	for(i=0; i<n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &x);
	
	qsort(arr, n, sizeof(int), compare);
	
	start=0;
	end=n-1;
	sum=0;
	result=0;
	
	while(start < end) {
		sum = arr[start] + arr[end];
		if(sum == x)
			result++;

		if(sum <= x)
			start++;
		else
			end--;
	}
	
	printf("%d\n", result);
	
	return 0;	
}