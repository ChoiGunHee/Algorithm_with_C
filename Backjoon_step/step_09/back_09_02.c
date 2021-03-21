/**
* 2021. 03. 21
* Creater : Gunhee Choi
* Problem Number : 2581
* Title : 소수

* Problem :
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최솟값을 찾는 프로그램을 작성하시오.

예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최솟값은 61이 된다.

* Input : 입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.
M과 N은 10,000이하의 자연수이며, M은 N보다 작거나 같다.

	60
	100

* Output : M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다. 
단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.

	620
	61

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
	int M, N;
	int sum = 0;
	int min = 10001;
	int i;
	
	scanf("%d %d", &M, &N);
	
	for(i=M; i<=N; i++) {
		if( check_prime_number(i) ) {
			sum += i;
			if(min > i) {
				min = i;
			}
		}
	}
	
	if(sum == 0) {
		printf("-1\n");
		return 0;
	}
	
	printf("%d\n%d\n", sum, min);
	
	return 0;
}