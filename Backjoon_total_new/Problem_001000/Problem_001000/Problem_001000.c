/**
* 2021. 02. 05
* Creater : Gunhee Choi
* Problem Number : 1000
* Title : A+B

* Problem :
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)
	1 2
	
* Output : 3

**/

#include <stdio.h>

int main() {
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d", a+b);
	return 0;
}