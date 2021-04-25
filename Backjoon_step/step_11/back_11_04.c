/**
* 2021. 04. 20
* Creater : Gunhee Choi
* Problem Number : 1018
* Title : 체스판 다시 칠하기

* Problem :
지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M*N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8*8 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8*8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

* Input :
첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.

	8 8
	WBWBWBWB
	BWBWBWBW
	WBWBWBWB
	BWBBBWBW
	WBWBWBWB
	BWBWBWBW
	WBWBWBWB
	BWBWBWBW

* Output : 첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

	1

**/

#include <stdio.h>
#define W 1
#define B 0
#define BUFFER_MAX 51

int W_PAN[8][8] = {1, 0, 1, 0, 1, 0, 1, 0,
				   0, 1, 0, 1, 0, 1, 0, 1,
				   1, 0, 1, 0, 1, 0, 1, 0,
				   0, 1, 0, 1, 0, 1, 0, 1,
				   1, 0, 1, 0, 1, 0, 1, 0,
				   0, 1, 0, 1, 0, 1, 0, 1,
				   1, 0, 1, 0, 1, 0, 1, 0,
				   0, 1, 0, 1, 0, 1, 0, 1};

int B_PAN[8][8] = {0, 1, 0, 1, 0, 1, 0, 1,
				   1, 0, 1, 0, 1, 0, 1, 0,
				   0, 1, 0, 1, 0, 1, 0, 1,
				   1, 0, 1, 0, 1, 0, 1, 0,
				   0, 1, 0, 1, 0, 1, 0, 1,
				   1, 0, 1, 0, 1, 0, 1, 0,
				   0, 1, 0, 1, 0, 1, 0, 1,
				   1, 0, 1, 0, 1, 0, 1, 0};

int main(void) {
	int N, M;				//N개의 줄
	char buffer[BUFFER_MAX];
	int test_pan[50][50];
	char temp;
	int W_count = 0;
	int B_count = 0;
	int result = 9999;
	int N_i, M_i;
	int i, j;
	
	scanf("%d %d", &N, &M);
	
	for(i=0; i<N; i++) {
		scanf("%s", buffer);
		for(j=0; j<M; j++) {
			if(buffer[j] == 'W')
				test_pan[i][j] = W;
			else
				test_pan[i][j] = B;
		}
	}
	
	
	for(N_i=0; N_i<=N-8; N_i++) {
		for(M_i=0; M_i<=M-8; M_i++) {
			
			W_count = 0;
			B_count = 0;
			
			//W_PAN Check
			for(i=0; i<8; i++) {
				for(j=0; j<8; j++) {
					if(W_PAN[i][j] != test_pan[N_i+i][M_i+j])
						W_count++;
				}
			}
			
			//B_PAN Check
			for(i=0; i<8; i++) {
				for(j=0; j<8; j++) {
					if(B_PAN[i][j] != test_pan[N_i+i][M_i+j])
						B_count++;
				}
			}
			
			temp = W_count < B_count ? W_count : B_count;
			result = result > temp ? temp : result;
		}
	}

	printf("%d\n", result);
	
	return 0;	
}