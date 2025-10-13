#include <stdio.h>
#include <math.h>

int main() {
    int A,B,C;
    int temp, result;

    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n", A+B-C);
    
    temp = B;
    int digits = 0;

    if (temp == 0) {
        digits = 1;
    } else {
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
    }

    result = A * (int)pow(10, digits) + B;
    printf("%d\n", result-C);
    
    return 0;
}