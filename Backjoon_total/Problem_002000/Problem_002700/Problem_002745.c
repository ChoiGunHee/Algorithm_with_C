/**
* 2025. 11. 22
* Creater : Gunhee Choi
* Problem Number : 2745
* Title : 진법 변환

* Problem :
B진법 수 N이 주어진다. 이 수를 10진법으로 바꿔 출력하는 프로그램을 작성하시오.
10진법을 넘어가는 진법은 숫자로 표시할 수 없는 자리가 있다. 이런 경우에는 다음과 같이 알파벳 대문자를 사용한다.
A: 10, B: 11, ..., F: 15, ..., Y: 34, Z: 35

* Input :
첫째 줄에 N과 B가 주어진다. (2 ≤ B ≤ 36)
B진법 수 N을 10진법으로 바꾸면, 항상 10억보다 작거나 같다.

    ZZZZZ 36
	
* Output :
첫째 줄에 B진법 수 N을 10진법으로 출력한다.

    60466175

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char N[1024];
    int B;
    long long result = 0;
    long long value;
    long long temp;
    int len = 0;

    scanf("%s %d", N, &B);
    len = strlen(N);

    for (int i = 0; i < len; i++) {
        temp = 1;
        value = 0;

        if (N[i] >= 'A' && N[i] <= 'Z') {
            value += (N[i] - 'A' + 10);
        } else {
            value += (N[i] - '0');
        }

        for (int j = 0; j < len-i-1; j++) {
            temp *= B;
        }

        result += temp * value;
    }

    printf("%lld\n", result);

    return 0;
}