/**
* 2025. 11. 21
* Creater : Gunhee Choi
* Problem Number : 2444
* Title : 별 찍기 - 7

* Problem :
예제를 보고 규칙을 유추한 뒤에 별을 찍어 보세요.

* Input :
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

    5
	
* Output :
첫째 줄부터 2×N-1번째 줄까지 차례대로 별을 출력한다.

    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N-i; j++) printf(" ");
        for(int k=1; k<=(2*i-1); k++) printf("*");
        printf("\n");
    }

    for(int i=N-1; i>=1; i--){
        for(int j=1; j<=N-i; j++) printf(" ");
        for(int k=1; k<=(2*i-1); k++)  printf("*");
        printf("\n");
    }

    return 0;
}