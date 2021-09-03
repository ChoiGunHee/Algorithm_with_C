/**
* 2021. 09. 01
* Creater : Gunhee Choi
* Problem Number : 19577
* Title : 수학은 재밌어

* Problem :
오일러는 수학을 정말 좋아해서 하루 종일 수학 공부만 하는 수학쟁이이다.

어느 날 오일러는 수학 공부를 하기 위해서 수학 책을 읽고 있던 중에 오일러 피 함수에 대해서 설명하는 부분을 보게 되었다. 오일러 피 함수는 다음과 같이 설명이 되어 있었다.

오일러 피 함수란 φ(n)으로 표기하며 1부터 n까지의 양의 정수 중에서 n과 서로소인 수의 개수를 나타내는 함수이다.

예를 들면 φ(6)은 1부터 6까지의 수 중 6과 서로소인 수의 개수를 말하는데 이는 1과 5로 두 개가 있으므로 φ(6) = 2이다.

오일러는 책의 내용을 곰곰이 읽던 중 어떤 문제가 떠올랐다. 문제의 내용은 다음과 같다.

어떤 양의 정수 n이 있다고 할 때, xφ(x) = n을 만족하는 양의 정수 x가 존재하는가?

고민에 빠진 오일러를 본 당신은 오일러의 궁금증을 해결해주기 위해서 직접 문제를 풀기로 결심했다. 그러므로 당신은 xφ(x) = n을 만족하는 x를 구하는 프로그램을 작성하면 된다.

* Input :
첫 번째 줄에 n이 입력으로 주어진다. (1 ≤ n ≤ 109)

	20

* Output :
xφ(x) = n을 만족하는 양의 정수 x가 존재하면 최소의 x를, 존재하지 않으면 −1을 출력한다.

	5
	
**/

/**

C++로 풀어야지 하...

**/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
	long long int num1 = *(long long int *)a;
	long long int num2 = *(long long int *)b;

	if(num1 < num2)
		return -1;
	else if(num1 > num2)
		return 1;

	return 0;
}

long long euler_phi(long long int n) {
	long long int result = n;
	long long int  i;
	
	for(i=2; i*i<=n; i++) {
		if(n%i==0) {
			result -= result/i;
			while(n%i==0)
				n/=i;
		}
	}
	
	if(n>1)
		result -= result/n;
	
	return result;
}

int main(void) {
	long long int n;
	long long int * arr;
	long long int arr_count=0;
	long long int result=-1;
	long long int i;
	
	scanf("%lld", &n);
	arr = (long long int *) malloc(sizeof(long long int)*n);
	
	for(i=1; i*i<=n; i++) {
		if(n%i==0) {
			arr[arr_count++]=i;
			if(i!=n/i)
				arr[arr_count++]=n/i;
		}
	}
	
	qsort(arr, arr_count, sizeof(long long int), compare);
	
	for(i=0; i<arr_count; i++)
		if(arr[i]*euler_phi(arr[i]) == n)
			result = arr[i];
	
	printf("%lld\n", result);
	
	return 0;	
}