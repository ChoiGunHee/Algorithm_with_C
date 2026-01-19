/**
* 2026. 01. 19
* Creater : Gunhee Choi
* Problem Number : 11478
* Title : 서로 다른 부분 문자열의 개수

* Problem :
문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수를 구하는 프로그램을 작성하시오.
부분 문자열은 S에서 연속된 일부분을 말하며, 길이가 1보다 크거나 같아야 한다.
예를 들어,
ababc의 부분 문자열은 a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고, 서로 다른것의 개수는 12개이다.

* Input :
첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000 이하이다.

    ababc

* Output :
첫째 줄에 S의 서로 다른 부분 문자열의 개수를 출력한다.
   
    12

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TrieNode {
    struct TrieNode* children[26]; // 알파벳 소문자 26개
    int isEnd; // 문자열의 끝 여부
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->isEnd = 0;
    return node;
}

void insert(TrieNode* root, const char* str) {
    TrieNode* current = root;
    while (*str) {
        int index = *str - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        current = current->children[index];
        str++;
    }
    current->isEnd = 1;
}

// 순회
int countNodes(TrieNode* node) {
    if (node == NULL) return 0;
    int count = 0;
    for (int i = 0; i < 26; i++) {
        count += countNodes(node->children[i]);
    }
    return count + 1; // 현재 노드 포함
}

int main(void) {
    char S[1001];
    scanf("%s", S);

    TrieNode* root = createNode();

    int length = strlen(S);
    for (int i = 0; i < length; i++) {
        insert(root, S + i);
    }

    int result = countNodes(root) - 1;
    printf("%d\n", result);

    return 0;
}