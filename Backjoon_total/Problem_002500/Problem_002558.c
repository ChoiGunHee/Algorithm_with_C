/**
* 2021. 08. 18
* Creater : Gunhee Choi
* Problem Number : 2558
* Title : A+B - 2

* Problem :
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 A, 둘째 줄에 B가 주어진다. (0 < A, B < 10)

	1
	2
	
* Output :
첫째 줄에 A+B를 출력한다.

	3

**/

#include <stdio.h>

int main(void) {
	int a, b;
	
	scanf("%d %d", &a, &b);
	printf("%d\n", a+b);
	
	return 0;	
}