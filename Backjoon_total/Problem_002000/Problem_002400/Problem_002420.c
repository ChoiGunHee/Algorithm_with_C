/**
* 2021. 08. 23
* Creater : Gunhee Choi
* Problem Number : 2420
* Title : 사파리월드

* Problem :
사파리월드는 인터넷으로만 존재하는 미스테리한 나라이다. 사파리월드에는 2개의 서브도메인이 seunghwan.royal.gov.sw와 kyuhyun.royal.gov.sw 이 있는데, 이것이 couple.royal.gov.sw으로 합쳐질 것이다. 그러나 도메인 관리 센터 SWNIC(센터장: 김동규)에는 엄격한 룰이 있다. 두 서브도메인을 합칠 때, 유명도의 차이가 너무 차이나지 않을 경우에만 두 서브도메인을 결혼시키는 것이다. 서브도메인의 유명도는 정수이다. 두 서브도메인의 유명도가 주어졌을 때, 그 차이를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 두 도메인의 유명도 N과 M이 주어진다. (-2,000,000,000 ≤ N, M ≤ 2,000,000,000)

	-2 5
	
* Output :
첫째 줄에 두 유명도의 차이 (|N-M|)을 출력한다.

	7

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	long long N, M;
	
	scanf("%lld %lld", &N, &M);
	printf("%lld\n", llabs(N-M));
	return 0;
}