/**
* 2021. 06. 15
* Creater : Gunhee Choi
* Problem Number : 10870
* Title : 스택

* Problem :
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오. 

* Input :
첫째 줄에 n이 주어진다. n은 20보다 작거나 같은 자연수 또는 0이다.

	10

* Output :
첫째 줄에 n번째 피보나치 수를 출력한다.

	55

**/

#include <stdio.h>

int main(void) {
	int n;
	int arr[25];
	int i;
	
	arr[0] = 0;
	arr[1] = 1;
	
	for(i=2; i<21; i++)
		arr[i] = arr[i-2] + arr[i-1];
	
	scanf("%d", &n);
	printf("%d\n", arr[n]);
	
	return 0;
}