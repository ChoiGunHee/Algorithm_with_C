#include <stdio.h>

int main() {
	int A,B;
	int temp_1, temp_10, temp_100, temp;
	
	scanf("%d", &A);
	scanf("%d", &B);
	temp = A*B;
	
	printf("%d\n", A*(B%10));
	B = (B-B%10)/10;
	
	printf("%d\n", A*(B%10));
	B = (B-B%10)/10;
	
	printf("%d\n", A*(B%10));
	
	printf("%d\n", temp);

	return 0;
}