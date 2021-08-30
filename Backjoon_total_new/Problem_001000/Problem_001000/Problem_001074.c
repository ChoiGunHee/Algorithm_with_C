/**
* 2021. 07. 29
* Creater : Gunhee Choi
* Problem Number : 1074
* Title : Z

* Problem :
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.

만약, N > 1이 라서 왼쪽 위에 있는 칸이 하나가 아니라면, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.

다음 예는 22 × 22 크기의 배열을 방문한 순서이다.

N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

다음은 N=3일 때의 예이다.

* Input :
첫째 줄에 정수 N, r, c가 주어진다.

	2 3 1
	
* Output :
r행 c열을 몇 번째로 방문했는지 출력한다.

	11

* 제한
	1 ≤ N ≤ 15
	0 ≤ r, c < 2N

**/

#include <stdio.h>

int N, r, c;
int result;

void Z(int n, int c, int r)
{
	int size = 1 << n;
	int half = size / 2;
	
	if (n == 0)
		return;
	
	if (c / half == 0 && r / half == 0) {
		Z(n - 1, c % half, r % half);
	} else if (c / half == 0 && r / half == 1) {
		result += half * half * 1;
		Z(n - 1, c % half, r % half);
	} else if (c / half == 1 && r / half == 0) {
		result += half * half * 2;
		Z(n - 1, c % half, r % half);
	} else {
		result += half * half * 3;
		Z(n - 1, c % half, r % half);
	}
}
int main() {
	scanf("%d %d %d", &N, &r, &c);
	
	Z(N, r, c);
	
	printf("%d\n", result);
	
	return 0;
}