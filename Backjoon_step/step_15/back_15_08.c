/**
* 2021. 08. 01
* Creater : Gunhee Choi
* Problem Number : 1463
* Title : 1로 만들기

* Problem :
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

	1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
	2. X가 2로 나누어 떨어지면, 2로 나눈다.
	3. 1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

* Input :
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

	10

* Output :
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

	3

**/

#include <stdio.h>
#define min(a,b)  (((a) < (b)) ? (a) : (b))

int arr[1000001];

int cal_One_N(int N) {
	int i;
	
	arr[1] = 0;
	for(i=2; i<=N; i++) {
		arr[i] = arr[i-1] + 1;
		
		if( i%2 == 0 )
			arr[i] = min(arr[i], arr[i/2] + 1);
		
		if( i%3 == 0 )
			arr[i] = min(arr[i], arr[i/3] + 1);
	}
	
	return arr[N];
}

int main(void) {
	int N;
	
	scanf("%d", &N);
	printf("%d\n", cal_One_N(N));
	
	return 0;
}