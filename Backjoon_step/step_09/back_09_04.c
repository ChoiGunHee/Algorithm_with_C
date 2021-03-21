/**
* 2021. 03. 21
* Creater : Gunhee Choi
* Problem Number : 1929
* Title : 소수 구하기

* Problem :
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

* Input : 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

	3 16

* Output : 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

	3
	5
	7
	11
	13
	
**/


#include <stdio.h>
#include <math.h>

int check_prime_number(int num) {
	int i;
	int end = (int) sqrt(num);
	int count;
	
	if(num == 1) return 0;
	
	for(i=2; i<=end; i++) {
		count = 1;
		if( num%i == 0 ) {
			count++;
			
			//소수 아님
			if(count > 1)
				return 0;
		}
	}
	
	//소수 맞음
	return 1;
}

int main() {
	int M, N;
	int i;
	
	scanf("%d %d", &M, &N);
	
	for(i=M; i<=N; i++) {
		if(check_prime_number(i))
			printf("%d\n", i);
	}
	
	return 0;
}