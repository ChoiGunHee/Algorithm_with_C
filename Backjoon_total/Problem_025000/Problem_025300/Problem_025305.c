/**
* 2026. 01. 05
* Creater : Gunhee Choi
* Problem Number : 25305
* Title : 커트라인

* Problem :
2022 연세대학교 미래캠퍼스 슬기로운 코딩생활에 N명의 학생들이 응시했다.
이들 중 점수가 가장 높은 k명은 상을 받을 것이다. 이 때, 상을 받는 커트라인이 몇 점인지 구하라.
커트라인이란 상을 받는 사람들 중 점수가 가장 가장 낮은 사람의 점수를 말한다.

* Input :
첫째 줄에는 응시자의 수 N과 상을 받는 사람의 수 k가 공백을 사이에 두고 주어진다.
둘째 줄에는 각 학생의 점수 x가 공백을 사이에 두고 주어진다.

    5 2
    100 76 85 93 98

* Output :
상을 받는 커트라인을 출력하라.
   
    98

**/

#include <stdio.h>

int main(void) {
    int N, K;
    int temp;
    scanf("%d %d", &N, &K);

    int scores[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &scores[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (scores[i] < scores[j]) {
                temp = scores[i];
                scores[i] = scores[j];
                scores[j] = temp;
            }
        }
    }

    printf("%d\n", scores[K - 1]);

    return 0;
}