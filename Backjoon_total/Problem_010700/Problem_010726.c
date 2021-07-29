/**
* 2021. 07. 29
* Creater : Gunhee Choi
* Problem Number : 11726
* Title : 2×n 타일링

* Problem :
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

* Input :
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

	9
	
* Output :
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
	
	55

**/

#include <stdio.h>
#define MAX_NUM 1001

long long dp_arr[MAX_NUM];

void dp() {
	int i;
	
	dp_arr[1] = 1;
	dp_arr[2] = 2;
	
	for(i=3; i<MAX_NUM; i++)
		dp_arr[i] = (dp_arr[i-2] + dp_arr[i-1]) % 10007;
}

int main() {
	int n;
	
	scanf("%d", &n);
	
	dp();
	
	printf("%lld\n", dp_arr[n]);
	
	return 0;
}