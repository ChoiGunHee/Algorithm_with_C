/**
* 2021. 03. 21
* Creater : Gunhee Choi
* Problem Number : 11653
* Title : 소인수분해

* Problem :
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

* Input : 첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

	72

* Output : N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다.

	2
	2
	2
	3
	3

**/

#include <stdio.h>
#include <math.h>

int main() {
	int N;
	int end;
	int i;
	
	scanf("%d", &N);
	if(N == 1)
		return 0;
	
	end = (int) sqrt(N);
	
	for(i=2; i<=end; i++) {
		if( N % i == 0 ) {
			printf("%d\n", i);
			N /= i;
			i--;
		}
	}
	
	if(N>1)
		printf("%d\n", N);
	
	return 0;
}