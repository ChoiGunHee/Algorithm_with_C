/**
* 2021. 09. 01
* Creater : Gunhee Choi
* Problem Number : 4355
* Title : 서로소

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

long long euler_phi(long long n) {
	long long result = n;
	long long  i;
	
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
	long long n=1;
	
	while(1) {
		scanf("%lld", &n);
		if(n==0)
			break;
		
		printf("%lld\n", euler_phi(n));
	}
	
	return 0;	
}