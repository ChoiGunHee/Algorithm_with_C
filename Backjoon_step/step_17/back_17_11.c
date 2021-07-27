/**
* 2021. 07. 27
* Creater : Gunhee Choi
* Problem Number : 1676
* Title : 팩토리얼 0의 개수

* Problem :
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

	10

* Output :
첫째 줄에 구한 0의 개수를 출력한다.

	2
	
**/

#include <stdio.h>

int main(void) {
	int N;
	int i;
	int result_2=0, result_5=0;
	
	scanf("%d", &N);
	
	for(i=2; i<=N; i*=2) result_2 += N/i;
	for(i=5; i<=N; i*=5) result_5 += N/i;
	
	printf("%d\n", result_2 < result_5 ? result_2 : result_5);
	
	return 0;	
}