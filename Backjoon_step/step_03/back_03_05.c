/**
* 2021. 02. 05
* Creater : Gunhee Choi
* Problem Number : 2741
* Title : N 찍기

* Problem :
자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.
	5
	
* Output : 첫째 줄부터 N번째 줄 까지 차례대로 출력한다.
	1
	2
	3
	4
	5

**/

#include <stdio.h>

int main() {
	int i, num;
	
	scanf("%d", &num);
	
	for(i=1; i<=num; i++) {
		printf("%d\n", i);	
	}
	
	return 0;
}