/**
* 2021. 08. 15
* Creater : Gunhee Choi
* Problem Number : 2667
* Title : 단지 번호 붙이기

* Problem :
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

* Input :
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

	7
	0110100
	0110101
	1110101
	0000111
	0100000
	0111110
	0111000
	
* Output :
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

	3
	7
	8
	9

**/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 30

int field[MAX_NUM][MAX_NUM];
int danji_cnt;

void search(int x, int y, int n) {
	field[x][y] = 0;
	danji_cnt++;
	
	if((x+1)<n)
		if(field[x+1][y])
			search(x+1, y, n);
	
	if(x>=1)
		if(field[x-1][y])
			search(x-1, y, n);
	
	if((y+1)<n)
		if(field[x][y+1])
			search(x, y+1, n);
	
	if(y>=1)
		if(field[x][y-1])
			search(x, y-1, n);
	
	return;
}

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 < num2)
		return -1;
	else if (num1 > num2)
		return 1;

	return 0;
}


int main(void) {
	int N;
	int count = 0;
	char str[MAX_NUM];
	int danji[MAX_NUM*MAX_NUM];
	int i, j;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++) {
		scanf("%s", str);
		for(j=0; j<N; j++) {
			field[i][j] = str[j] - '0';
		}
	}
	
	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if(field[i][j]) {
				danji_cnt = 0;
				search(i, j, N);
				danji[count++] = danji_cnt;
			}
		}
	}
	
	qsort(danji, count, sizeof(int), compare);
	
	printf("%d\n", count);
	for(i=0; i<count; i++)
		printf("%d\n", danji[i]);
	
	return 0;	
}