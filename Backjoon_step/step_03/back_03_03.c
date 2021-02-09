/**
* 2021. 02. 05
* Creater : Gunhee Choi
* Problem Number : 8393
* Title : 합

* Problem :
n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 n (1 ≤ n ≤ 10,000)이 주어진다.
	3
	
* Output : 1부터 n까지 합을 출력한다.
	6

**/

#include <stdio.h>

int main() {
	int i, n;
	int sum = 0;
	
	scanf("%d", &n);
	for(i=1; i<=n; i++)
		sum += i;
	printf("%d\n", sum);
	
	return 0;
}