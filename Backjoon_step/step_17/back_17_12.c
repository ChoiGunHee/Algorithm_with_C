/**
* 2021. 07. 27
* Creater : Gunhee Choi
* Problem Number : 2004
* Title : 조합 0의 개수

* Problem :

(N M) 의 끝자리 의 개수를 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 정수 ,  (, )이 들어온다.

	25 12

* Output :
첫째 줄에 의 끝자리 의 개수를 출력한다.

	2
	
**/

#include <stdio.h>

int main(void) {
	long long N, M;
	long long result_2=0, result_5=0;
	long long i;
	
	scanf("%lld %lld", &N, &M);
	
	//2
	for(i=2; i<=N; i*=2)
		result_2 += N/i;
	
	if (M != 0)
		for(i=2; i<=M; i*=2)
			result_2 -= M/i;
	
	if (M != N)
		for(i=2; i<=N-M; i*=2)
			result_2 -= (N-M)/i;
	
	//5
	for(i=5; i<=N; i*=5)
		result_5 += N/i;
	
	if (M != 0)
		for(i=5; i<=M; i*=5)
			result_5 -= M/i;
	
	if (M != N)
		for(i=5; i<=N-M; i*=5)
			result_5 -= (N-M)/i;
	
	printf("%lld\n", result_2 > result_5 ? result_5 : result_2);
	
	return 0;	
}