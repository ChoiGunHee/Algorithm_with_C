/**
* 2021. 02. 05
* Creater : Gunhee Choi
* Problem Number : 	10430
* Title : 나머지

* Problem :
(A+B)%C는 ((A%C) + (B%C))%C 와 같을까?

(A×B)%C는 ((A%C) × (B%C))%C 와 같을까?

세 수 A, B, C가 주어졌을 때, 위의 네 가지 값을 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)
	5 8 4

* Output :
첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.
	1
	1
	0
	0
**/

#include <stdio.h>

int main() {
	int A,B,C;
	scanf("%d %d %d", &A, &B, &C);
	
	printf("%d\n", (A+B)%C);
	printf("%d\n", ((A%C)+(B%C))%C);
	printf("%d\n", (A*B)%C);
	printf("%d\n", ((A%C)*(B%C))%C);
	return 0;
}