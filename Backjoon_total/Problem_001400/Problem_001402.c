/**
* 2021. 07. 28
* Creater : Gunhee Choi
* Problem Number : 1402
* Title : 아무래도이문제는A번난이도인것같다

* Problem :
어떤 정수 A가 있으면 그 숫자를 A = a1 * a2 * a3 * a4 ... * an으로 했을 때 A' = a1 + a2 + a3 ... + an이 성립하면 "A는 A'으로 변할 수 있다"라고 한다. (ai는 정수) 만약 A'이 A''으로 변할 수 있으면 "A는 A''으로 변할 수 있다"라고 한다.

이때 A와 B가 주어지면 A는 B로 변할 수 있는지 판별하시오.

* Input :
첫째 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 100)이 주어진다. 테스트 케이스마다 두 정수 A, B(-231 ≤ A, B ≤ 231-1)가 주어진다.

	1
	6 5
	
* Output :
각각의 테스트 케이스마다 한 줄에 변할 수 있으면 yes, 아니면 no를 출력한다.

	yes
	
**/

#include <stdio.h>

int main(void) {
	int T, A, B;
	int i;
	
	scanf("%d", &T);
	
	for(i=0; i<T; i++) {
		scanf("%d %d", &A, &B);
		//1*1*1... -1*-1*-1.. 도 가능
		printf("yes\n");
	}

	return 0;	
}