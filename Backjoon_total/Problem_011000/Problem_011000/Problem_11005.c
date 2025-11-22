/**
* 2025. 11. 22
* Creater : Gunhee Choi
* Problem Number : 11005
* Title : 진법 변환 2

* Problem :
10진법 수 N이 주어진다. 이 수를 B진법으로 바꿔 출력하는 프로그램을 작성하시오.

10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.

A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

* Input :
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36) N은 10억보다 작거나 같은 자연수이다.

    60466175 36
	
* Output :
첫째 줄에 10진법 수 N을 B진법으로 출력한다.

    ZZZZZ

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    long long N;
    int B;
    char result[64];
    int index = 0;

    scanf("%lld %d", &N, &B);

    while (N > 0) {
        int remainder = N % B;
        if (remainder >= 10) {
            result[index++] = 'A' + (remainder - 10);
        } else {
            result[index++] = '0' + remainder;
        }
        N /= B;
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");

    return 0;
}