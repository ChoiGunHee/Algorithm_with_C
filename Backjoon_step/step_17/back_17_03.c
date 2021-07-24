/**
* 2021. 07. 24
* Creater : Gunhee Choi
* Problem Number : 2609
* Title : 최대공약수와 최소공배수

* Problem :
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

	24 18

* Output :
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

	6
	72

**/

#include <stdio.h>

int gcd(int a, int b)
{
    int temp;
	
	while(b)
	{
		temp = a % b;
		a = b;
		b = temp;
	}
	
    return a;
}

int main(void) {
	int num1, num2;
	int gcd_num;
	int lcm_num;
	
	scanf("%d %d", &num1, &num2);
	
	gcd_num = gcd(num1, num2);
	lcm_num = num1 * num2 / gcd_num;
	
	printf("%d\n%d\n", gcd_num, lcm_num);
	
	return 0;	
}