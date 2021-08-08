/**
* 2021. 07. 22
* Creater : Gunhee Choi
* Problem Number : 2630
* Title : 색종이 만들기

* Problem :
자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

	10 11 12

* Output :
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

	4
	
**/

#include <stdio.h>

long long mul(int a, int b, int c) {
	long long tmp;
	long long result;
	
	if(b==0)
		return 1;
	
	tmp = mul(a, b/2, c);
	result = (tmp * tmp)%c;
	
	if(b%2)
		return (result*a)%c;
	
	return result;
}
 
int main() {
	int A, B, C;
	long long result;
	
	scanf("%d %d %d", &A, &B, &C);
	
	result = mul(A, B, C);
	
	printf("%lld\n", result);
	
	return 0;
}