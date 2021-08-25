/**
* 2021. 08. 25
* Creater : Gunhee Choi
* Problem Number : 11401
* Title : 이항 계수 3

* Problem :
자연수 과 정수 가 주어졌을 때 이항 계수 
를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 과 가 주어진다. (1 ≤  ≤ 4,000,000, 0 ≤  ≤ )

	5 2
	
* Output :
를 1,000,000,007로 나눈 나머지를 출력한다.

	10

**/

#include <stdio.h>
#define VAL_MOD 1000000007LL

long long mul(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y%2 != 0) {
            result *= x;
            result %= VAL_MOD;
        }
        x *= x;
        x %= VAL_MOD;
        y/=2;
    }
    return result;
}

int main(void) {
	long long N, K;
	long long result=1;
	long long tmp1=1;
	long long tmp2=1;
	long long tmp3;
	long long i, j;
	
	scanf("%lld %lld", &N, &K);
	
	for(long long i=1; i<=N; i++) {
		tmp1*=i;
		tmp1%=VAL_MOD;
	}
	
	for(long long i=1; i<=K; i++) {
		tmp2*=i;
		tmp2%=VAL_MOD;
	}
	
	for(long long i=1; i<=(N-K); i++) {
		tmp2*=i;
		tmp2%=VAL_MOD;
	}
	
	tmp3=mul(tmp2,VAL_MOD-2);
	tmp3%=VAL_MOD;
	
	result=tmp1*tmp3;
	result%=VAL_MOD;
	
	printf("%lld\n", result);
	return 0;	
}