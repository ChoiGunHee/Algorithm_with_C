/**
* 2021. 02. 05
* Creater : Gunhee Choi
* Problem Number : 10950
* Title : A+B - 3

* Problem :
두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있으며, 각 줄에 A와 B가 주어진다. (0 < A, B < 10)
	5
	1 1
	2 3
	3 4
	9 8
	5 2
	
* Output : 각 테스트 케이스마다 A+B를 출력한다.
	2
	5
	7
	17
	7

**/

#include <stdio.h>

int main() {
	int i, num;
	int A, B;
	
	scanf("%d", &num);
	
	for(i=0; i<num; i++) {
		scanf("%d %d", &A, &B);
		printf("%d\n", A+B);	
	}
	
	return 0;
}