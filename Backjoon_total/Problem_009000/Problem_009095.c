/**
* 2021. 07. 29
* Creater : Gunhee Choi
* Problem Number : 9095
* Title : 1,2,3 더하기

* Problem :
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

	1+1+1+1
	1+1+2
	1+2+1
	2+1+1
	2+2
	1+3
	3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

	3
	4
	7
	10

* Output :
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

	7
	44
	274

**/

#include <stdio.h>
#define MAX_NUM 12

int dp_arr[MAX_NUM];

int dp() {
	int i;
	
	dp_arr[1] = 1;
	dp_arr[2] = 2;
	dp_arr[3] = 4;
	
	for(i=4; i<=MAX_NUM; i++) {
		dp_arr[i] = dp_arr[i-3] + dp_arr[i-2] + dp_arr[i-1];
	}
}

int main(void) {
	int T, n;
	int i;
	
	dp();
	
	scanf("%d", &T);
	
	for(i=0; i<T; i++) {
		scanf("%d", &n);
		printf("%d\n", dp_arr[n]);
	}
	
	return 0;	
}