/**
* 2021. 08. 26
* Creater : Gunhee Choi
* Problem Number : 5543
* Title : 상근날드

* Problem :
상근날드에서 가장 잘 팔리는 메뉴는 세트 메뉴이다. 주문할 때, 자신이 원하는 햄버거와 음료를 하나씩 골라, 세트로 구매하면, 가격의 합계에서 50원을 뺀 가격이 세트 메뉴의 가격이 된다.

햄버거는 총 3종류 상덕버거, 중덕버거, 하덕버거가 있고, 음료는 콜라와 사이다 두 종류가 있다.

햄버거와 음료의 가격이 주어졌을 때, 가장 싼 세트 메뉴의 가격을 출력하는 프로그램을 작성하시오.

* Input :
입력은 총 다섯 줄이다. 첫째 줄에는 상덕버거, 둘째 줄에는 중덕버거, 셋째 줄에는 하덕버거의 가격이 주어진다. 넷째 줄에는 콜라의 가격, 다섯째 줄에는 사이다의 가격이 주어진다. 모든 가격은 100원 이상, 2000원 이하이다.

	800
	700
	900
	198
	330
	
* Output :
첫째 줄에 가장 싼 세트 메뉴의 가격을 출력한다.

	848

**/

#include <stdio.h>

int main(void) {
	int s_buerger=3000;
	int s_beverage=3000;
	int tmp;
	int i;
	
	for(i=0; i<3; i++) {
		scanf("%d", &tmp);
		if(tmp<s_buerger)
			s_buerger=tmp;
	}
	
	for(i=0; i<2; i++) {
		scanf("%d", &tmp);
		if(tmp<s_beverage)
			s_beverage=tmp;
	}
	
	printf("%d\n", s_buerger+s_beverage-50);
	
	return 0;	
}