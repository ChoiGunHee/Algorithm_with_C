/**
* 2021. 08. 30
* Creater : Gunhee Choi
* Problem Number : 5337
* Title : 웰컴

* Problem :
자연수 n이 주어졌을 때, GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 자연수 n (1 ≤ n ≤ 1012)이 주어진다.

	45
	
* Output :
GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 출력한다.

	24
	
**/

#include <stdio.h>

int main(void) {
	long long n;
	long long i;
	long long result;
	
	scanf("%lld", &n);
	
	result = n;
	for(i=2; i*i<=n; i++) {
		if(n%i==0) {
			result -= result/i;
			while(n%i==0)
				n/=i;
		}
	}
	
	if(n>1)
		result -= result/n;
	
	printf("%lld\n", result);
	return 0;	
}