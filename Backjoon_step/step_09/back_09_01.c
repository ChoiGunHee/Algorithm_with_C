/**
* 2021. 03. 13
* Creater : Gunhee Choi
* Problem Number : 1978
* Title : 소수 찾기

* Problem :
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

* Input : 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

	4
	1 3 5 7

* Output : 주어진 수들 중 소수의 개수를 출력한다.

	3

**/

#include <stdio.h>

int check_prime_number(int num) {
	int i;
	int end = num/2;
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
	int i;
	int problem_count;
	int number;
	int result = 0;
	scanf("%d", &problem_count);
	
	for(i=0; i<problem_count; i++) {
		scanf("%d", &number);
		if( check_prime_number(number) )
			result++;
	}
	
	printf("%d\n", result);
	return 0;
}