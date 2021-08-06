/**
* 2021. 08. 06
* Creater : Gunhee Choi
* Problem Number : 1780
* Title : 종이의 개수

* Problem :
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1의 세 값 중 하나가 저장되어 있다. 우리는 이 행렬을 적절한 크기로 자르려고 하는데, 이때 다음의 규칙에 따라 자르려고 한다.

	(1) 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
	(2) (1)이 아닌 경우에는 종이를 같은 크기의 9개의 종이로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

* Input :
첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

	9
	0 0 0 1 1 1 -1 -1 -1
	0 0 0 1 1 1 -1 -1 -1
	0 0 0 1 1 1 -1 -1 -1
	1 1 1 0 0 0 0 0 0
	1 1 1 0 0 0 0 0 0
	1 1 1 0 0 0 0 0 0
	0 1 -1 0 1 -1 0 1 -1
	0 -1 1 0 1 -1 0 1 -1
	0 1 -1 1 0 -1 0 1 -1

* Output :
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

	10
	12
	11
	
**/

#include <stdio.h>
#define MAX_N 2200

int paper[MAX_N][MAX_N];
int count_papers[3];

void count_paper(int x, int y, int n) {
	int check = paper[x][y];
	int div;
	int flag = 1;
	int i, j;
	
	for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            if(paper[x+i][y+j] != check) {
				flag = 0;
				break;
			}
		
	
    if(flag) {
        count_papers[check+1]++;
        return;
    }
 
    div = n / 3;
	
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            count_paper(x+div*i, y+div*j, div);
}

int main(void) {
	int N;
	int i, j;
	
	scanf("%d", &N);
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			scanf("%d", &paper[i][j]);
	
	count_paper(0, 0, N);
	
	printf("%d\n%d\n%d\n", count_papers[0], count_papers[1], count_papers[2]);
	
	return 0;	
}