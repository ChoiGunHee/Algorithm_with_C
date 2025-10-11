#include <stdio.h>
#include <stdlib.h>

int main() {
    char * S = malloc(1001*sizeof(char));
    int i;
    
    scanf("%s", S); scanf("%d", &i);
    
    printf("%c\n", S[i-1]);
    return 0;
}