/**
* 2021. 04. 08
* Creater : Gunhee Choi
* Problem Number : 10872
* Title : 팩토리얼

* Problem :
0보다 크거나 같은 정수 N이 주어진다. 이때, N!을 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

	10

* Output : 첫째 줄에 N!을 출력한다.

	3628800

**/

#include <stdio.h>
int factorial(int n) {
	if(n == 1 || n == 0)  return 1;
	else return n * factorial( n-1 );
}

int main(void) {
	int n;
	
	scanf("%d", &n);
	printf("%d\n", factorial(n));
	
	return 0;
}

/*
int factorial(int n) {
	int result = 1;
	int i;
	
	for(i=1; i<=n; i++) {
		result *= i;
	}
	
	return result;
}

int main(void) {
	
	int n;
	
	scanf("%d", &n);
	printf("%d\n", factorial(n));
	return 0;
}
*/