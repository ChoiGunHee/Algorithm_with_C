/**
* 2021. 07. 23
* Creater : Gunhee Choi
* Problem Number : 1076
* Title : 저항

* Problem :
전자 제품에는 저항이 들어간다. 저항은 색 3개를 이용해서 그 저항이 몇 옴인지 나타낸다.

처음 색 2개는 저항의 값이고, 마지막 색은 곱해야 하는 값이다.

저항의 값은 다음 표를 이용해서 구한다.

색	값	곱
black	0	1
brown	1	10
red		2	100
orange	3	1000
yellow	4	10000
green	5	100000
blue	6	1000000
violet	7	10000000
grey	8	100000000
white	9	1000000000

예를 들어, 저항에 색이 yellow, violet, red였다면 저항의 값은 4,700이 된다.

* Input :
첫째 줄에 첫 번째 색, 둘째 줄에 두 번째 색, 셋째 줄에 세 번째 색이 주어진다. 색은 모두 위의 표에 쓰여 있는 색만 주어진다.

	yellow
	violet
	red
	
* Output :
입력으로 주어진 저항의 저항값을 계산하여 첫째 줄에 출력한다.
	
	4700

**/

#include <stdio.h>
#include <string.h>

char colors[10][30] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
int resistance[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
long long mul_num[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int check_value(char * color) {
	int i;
	
	for(i=0; i<10; i++) {
		if(strcmp(color, colors[i]) == 0)
			return i;
	}
	
	return -1;
}

int main() {
	char color[30];
	long long result = 0;
	
	scanf("%s", color);
	result = 10* resistance[check_value(color)];
	
	scanf("%s", color);
	result += resistance[check_value(color)];
	
	scanf("%s", color);
	result *= mul_num[check_value(color)];

	printf("%lld\n", result);
	
	return 0;
}