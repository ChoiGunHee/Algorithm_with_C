/**
* 2021. 08. 29
* Creater : Gunhee Choi
* Problem Number : 2417
* Title : 숫자 카드 

* Problem :
정수가 주어지면, 그 수의 정수 제곱근을 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 정수 n이 주어진다. (0 ≤ n < 263)

	122333444455555

* Output :
첫째 줄에 q2 ≥ n인 가장 작은 음이 아닌 정수 q를 출력한다.

	11060446

**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	long long n;
	long long result;
	
	scanf("%lld", &n);
	result = (long long) sqrt((double)n);
	
	if(n*n == result)
		printf("%lld\n", result);
	else
		printf("%lld\n", result+1);
	
	return 0;	
}