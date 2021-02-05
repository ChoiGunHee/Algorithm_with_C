/**
* 2021. 01. 17
* Creater : Gunhee Choi
* Problem Number : 1001
* Title : A-B

* Problem :
두 정수 A와 B를 입력받은 다음, A-B를 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)
	3 2

* Output : 1

**/

#include <stdio.h>

int main() {
	int a,b;
	scanf("%d %d", &a, &b);
	printf("%d", a-b);
	return 0;
}