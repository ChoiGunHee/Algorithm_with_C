/**
* 2021. 07. 20
* Creater : Gunhee Choi
* Problem Number : 1541
* Title : 읽어버린 괄호

* Problem :
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	29904	14090	11386	47.192%
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다. 그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을 최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

* Input :
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로 이루어져 있고, 가장 처음과 마지막 문자는 숫자이다. 그리고 연속해서 두 개 이상의 연산자가 나타나지 않고, 5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다. 입력으로 주어지는 식의 길이는 50보다 작거나 같다.

	55-50+40

* Output :
첫째 줄에 정답을 출력한다.

	-35

**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int check_number(char c) {
	int result;
	
	switch (c) {
		case '1' :
		case '2' :
		case '3' :
		case '4' :
		case '5' :
		case '6' :
		case '7' :
		case '8' :
		case '9' :
			result = c - '0';
			break;
		default :
			result = -1;
			break;
	}
	
	return result;	
}

int main(void) {
	char str[51];
	int len;
	int i, j;
	int count = 0;
	int tmp_number[5];
	int tmp_sum = 0;
	int tmp;
	int result = 0;
	
	scanf("%s", str);
	len = strlen(str);
	
	for(i=0; i<len; i++) {
		tmp = check_number(str[i]);
		
		if(tmp != -1) {
			tmp_number[count] = tmp;
			count++;
		} else {
			tmp = count;
			for(j=0; j<count; j++) {
				tmp_sum = pow(10, tmp+1) * tmp_number[j];
				tmp--;
			}
			
			if(str[i] == '+')
				result += tmp_sum;
			else
				result -= tmp_sum;
		}
		
		
	}
	
	printf("%d\n", result);
	
	return 0;
}