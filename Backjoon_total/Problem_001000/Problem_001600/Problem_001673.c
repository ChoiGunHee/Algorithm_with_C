/**
* 2021. 07. 26
* Creater : Gunhee Choi
* Problem Number : 1673
* Title : 치킨 쿠폰

* Problem :
강민이는 치킨 한 마리를 주문할 수 있는 치킨 쿠폰을 n장 가지고 있다. 이 치킨집에서는 치킨을 한 마리 주문할 때마다 도장을 하나씩 찍어 주는데, 도장을 k개 모으면 치킨 쿠폰 한 장으로 교환할 수 있다.

강민이가 지금 갖고 있는 치킨 쿠폰으로 치킨을 최대 몇 마리나 먹을 수 있는지 구하여라. 단, 치킨을 주문하기 위해서는 반드시 치킨 쿠폰을 갖고 있어야 한다.

* Input :
여러 줄에 걸쳐서 자연수 n과 k가 주어진다.

	4 3
	10 3
	100 5

* Output :
각 입력마다 한 줄에 정답을 출력한다.

	5
	14
	124

**/

#include <stdio.h>

int main(void) {
	int n, k;
	int coupon, stamp;
	int result;
	
	while(scanf("%d %d",&n,&k)!=EOF){
        coupon = n;
		stamp = 0;
		result = 0;
		
        while(coupon){
            result += coupon;
            stamp += coupon;
            coupon = 0;
            coupon += stamp/k;
            stamp %= k;
        }
        
		printf("%d\n", result);
    }
	
	return 0;	
}