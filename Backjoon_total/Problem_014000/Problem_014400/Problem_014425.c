/**
* 2026. 01. 08
* Creater : Gunhee Choi
* Problem Number : 14425
* Title : 문자열 집합

* Problem :
총 N개의 문자열로 이루어진 집합 S가 주어진다.
입력으로 주어지는 M개의 문자열 중에서 집합 S에 포함되어 있는 것이 총 몇 개인지 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 문자열의 개수 N과 M (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 10,000)이 주어진다.
다음 N개의 줄에는 집합 S에 포함되어 있는 문자열들이 주어진다.
다음 M개의 줄에는 검사해야 하는 문자열들이 주어진다.
입력으로 주어지는 문자열은 알파벳 소문자로만 이루어져 있으며, 길이는 500을 넘지 않는다. 집합 S에 같은 문자열이 여러 번 주어지는 경우는 없다.

    5 11
    baekjoononlinejudge
    startlink
    codeplus
    sundaycoding
    codingsh
    baekjoon
    codeplus
    codeminus
    startlink
    starlink
    sundaycoding
    codingsh
    codinghs
    sondaycoding
    startrink
    icerink

* Output :
첫째 줄에 M개의 문자열 중에 총 몇 개가 집합 S에 포함되어 있는지 출력한다.
   
    4

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 10007

typedef struct Node {
    char str[501];
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

int hashFunction(const char* str) {
    int hash = 0;
    while (*str) {
        hash = (hash * 31 + *str) % HASH_SIZE;
        str++;
    }
    return hash;
}

void insert(const char* str) {
    int hash = hashFunction(str);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->str, str);
    newNode->next = hashTable[hash];
    hashTable[hash] = newNode;
}

int search(const char* str) {
    int hash = hashFunction(str);
    Node* current = hashTable[hash];
    while (current) {
        if (strcmp(current->str, str) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main(void) {
    int N, M;
    int count = 0;
    char query[501];

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        char str[501];
        scanf("%s", str);
        insert(str);
    }

    for (int i = 0; i < M; i++) {
        scanf("%s", query);
        if (search(query)) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}