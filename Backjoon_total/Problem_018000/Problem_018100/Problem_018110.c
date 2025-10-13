#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare_int(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main(void) {
    int N;
    int * scores;
    int ignore_num;
    double result=0;
    int print_result=0;

    scanf("%d", &N);
    scores = malloc(N*sizeof(int));

    for(int i=0; i<N; i++) {
        scanf("%d", &scores[i]);
    }
    
    if (N == 0) {
        puts("0");
        return 0;
    }

    qsort(scores, N, sizeof(int), compare_int);

    ignore_num = round(N*0.15);
    for(int i=ignore_num; i<N-ignore_num; i++) {
        result += scores[i];
    }
    print_result = round(result/(N-2*ignore_num));

    printf("%d\n", print_result);

    free(scores);

    return 0;
}