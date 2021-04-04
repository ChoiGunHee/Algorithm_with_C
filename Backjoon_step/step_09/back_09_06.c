/**
* 2021. 04. 04
* Creater : Gunhee Choi
* Problem Number : 9020
* Title : 골드바흐의 추측

* Problem :
1보다 큰 자연수 중에서  1과 자기 자신을 제외한 약수가 없는 자연수를 소수라고 한다. 예를 들어, 5는 1과 5를 제외한 약수가 없기 때문에 소수이다. 하지만, 6은 6 = 2 × 3 이기 때문에 소수가 아니다.

골드바흐의 추측은 유명한 정수론의 미해결 문제로, 2보다 큰 모든 짝수는 두 소수의 합으로 나타낼 수 있다는 것이다. 이러한 수를 골드바흐 수라고 한다. 또, 짝수를 두 소수의 합으로 나타내는 표현을 그 수의 골드바흐 파티션이라고 한다. 예를 들면, 4 = 2 + 2, 6 = 3 + 3, 8 = 3 + 5, 10 = 5 + 5, 12 = 5 + 7, 14 = 3 + 11, 14 = 7 + 7이다. 10000보다 작거나 같은 모든 짝수 n에 대한 골드바흐 파티션은 존재한다.

2보다 큰 짝수 n이 주어졌을 때, n의 골드바흐 파티션을 출력하는 프로그램을 작성하시오. 만약 가능한 n의 골드바흐 파티션이 여러 가지인 경우에는 두 소수의 차이가 가장 작은 것을 출력한다.

* Input : 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고 짝수 n이 주어진다.

	3
	8
	10
	16

* Output : 각 테스트 케이스에 대해서 주어진 n의 골드바흐 파티션을 출력한다. 출력하는 소수는 작은 것부터 먼저 출력하며, 공백으로 구분한다.

	3 5
	5 5
	5 11

 * 제한 : 4 ≤ n ≤ 10,000
**/

#include <stdio.h>
#define MAX_ARR 10000

int primeArr[MAX_ARR + 1];

void eratos(int n)
{
	int i, j;
	
    if (n <= 1) return;

	for (int i = 0; i <= n; i++)
	    primeArr[i] = 1;

	for (int i = 2; i * i <= n; i++)
	{
		if (primeArr[i])
			for (int j = i * i; j <= n; j += i)
			    primeArr[j] = 0;
	}
}

void goldbach(int n) {
	int i, j;
	int mid = n / 2;
	
	for ( i=j=mid; i<=n; i--, j++)
		if (primeArr[i] && primeArr[j]) {
			printf("%d %d\n", i, j);
			return;
		}

}

int main(void) {
	int problem_count;
	int in_n;
	int result1, result2;
	int i, j, m;

	eratos(MAX_ARR);
	
	scanf("%d", &problem_count);
	
	for(i=0; i<problem_count; i++) {
		scanf("%d", &in_n);
		goldbach(in_n);
	}
}




