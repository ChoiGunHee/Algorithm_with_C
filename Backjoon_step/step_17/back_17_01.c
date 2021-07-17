/**
* 2021. 07. 15
* Creater : Gunhee Choi
* Problem Number : 5086
* Title : 배수와 약수

* Problem :
4 × 3 = 12이다.

이 식을 통해 다음과 같은 사실을 알 수 있다.

3은 12의 약수이고, 12는 3의 배수이다.

4도 12의 약수이고, 12는 4의 배수이다.

두 수가 주어졌을 때, 다음 3가지 중 어떤 관계인지 구하는 프로그램을 작성하시오.

첫 번째 숫자가 두 번째 숫자의 약수이다.
첫 번째 숫자가 두 번째 숫자의 배수이다.
첫 번째 숫자가 두 번째 숫자의 약수와 배수 모두 아니다.

* Input :
입력은 여러 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 10,000이 넘지않는 두 자연수로 이루어져 있다. 마지막 줄에는 0이 2개 주어진다. 두 수가 같은 경우는 없다.

	8 16
	32 4
	17 5
	0 0

* Output :
각 테스트 케이스마다 첫 번째 숫자가 두 번째 숫자의 약수라면 factor를, 배수라면 multiple을, 둘 다 아니라면 neither를 출력한다.

	factor
	multiple
	neither

**/

#include <stdio.h>

int main(void) {
	int N, M;
	
	while(1) {
		scanf("%d %d", &N, &M);
		if( N == 0 && M == 0 )
			break;
		
		if( (M % N) == 0 ) {
			//약수
			printf("factor\n");
		} else if( (N % M) == 0) {
			//배수
			printf("multiple\n");
		} else {
			printf("neither\n");
		}
	}
	
	return 0;
}