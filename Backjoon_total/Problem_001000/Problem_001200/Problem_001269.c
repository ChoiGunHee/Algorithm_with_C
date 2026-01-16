/**
* 2026. 01. 16
* Creater : Gunhee Choi
* Problem Number : 1269
* Title : 대칭 차집합

* Problem :
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다. 이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오.
두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.

예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로,
대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

* Input :
첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다.
둘째 줄에는 집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다.
각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.

    3 5
    1 2 4
    2 3 4 5 6

* Output :
첫째 줄에 대칭 차집합의 원소의 개수를 출력한다.
   
    4

**/

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int binary_search(int* arr, int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) {
            return 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main(void) {
    int a_size, b_size;
    int result = 0;
    scanf("%d %d", &a_size, &b_size);

    int* A = (int*)malloc(a_size * sizeof(int));
    int* B = (int*)malloc(b_size * sizeof(int));

    for (int i = 0; i < a_size; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < b_size; i++)
        scanf("%d", &B[i]);

    qsort(A, a_size, sizeof(int), compare);
    qsort(B, b_size, sizeof(int), compare);

    for (int i = 0; i < a_size; i++) {
        if (!binary_search(B, b_size, A[i])) {
            result++;
        }
    }

    for (int i = 0; i < b_size; i++) {
        if (!binary_search(A, a_size, B[i])) {
            result++;
        }
    }

    printf("%d\n", result);
    free(A);
    free(B);

    return 0;
}