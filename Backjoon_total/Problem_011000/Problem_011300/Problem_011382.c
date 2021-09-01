/**
* 2021. 09. 01
* Creater : Gunhee Choi
* Problem Number : 11382
* Title : 꼬마 정민

* Problem :
꼬마 정민이는 이제 A + B 정도는 쉽게 계산할 수 있다. 이제 A + B+ C를 계산할 차례이다!

* Input :
첫 번째 줄에 A, B, C (1 ≤ A, B, C ≤ 1012)이 공백을 사이에 두고 주어진다.

	77 77 7777
	
* Output :
A+B+C의 값을 출력한다.

	7931
	
**/

#include <stdio.h>

int main(void) {
	long long A,B,C;
	
	scanf("%lld %lld %lld", &A, &B, &C);
	printf("%lld\n", A+B+C);
	
	return 0;	
}