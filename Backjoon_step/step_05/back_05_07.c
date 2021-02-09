/**
* 2021. 02. 09
* Creater : Gunhee Choi
* Problem Number : 4344
* Title : 평균은 넘겠지

* Problem :
대학생 새내기들의 90%는 자신이 반에서 평균은 넘는다고 생각한다. 당신은 그들에게 슬픈 진실을 알려줘야 한다.

* Input : 첫째 줄에는 테스트 케이스의 개수 C가 주어진다.
둘째 줄부터 각 테스트 케이스마다 학생의 수 N(1 ≤ N ≤ 1000, N은 정수)이 첫 수로 주어지고, 이어서 N명의 점수가 주어진다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.
	5
	5 50 50 70 80 100
	7 100 95 90 80 70 60 50
	3 70 90 80
	3 70 90 81
	9 100 99 98 97 96 95 94 93 91
	
* Output : 각 케이스마다 한 줄씩 평균을 넘는 학생들의 비율을 반올림하여 소수점 셋째 자리까지 출력한다.
	40.000%
	57.143%
	33.333%
	66.667%
	55.556%
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int problem_count;
	int * arr_score;
	int arr_size, sum, count;
	double avg;
	int i, j;
	
	//문제 개수 입력
	scanf("%d", &problem_count);
	
	//문제 수 반복
	for(i=0; i<problem_count; i++) {
		scanf("%d", &arr_size);
		
		arr_score = (int *) malloc(sizeof(int)*arr_size);
		for(j=0; j<arr_size; j++) {
			scanf("%d", &arr_score[j]);	
		}
		
		//평균 구하기
		sum = 0;
		avg = 0;
		for(j=0; j<arr_size; j++) {
			sum += arr_score[j];
		}
		avg = (double)sum/arr_size;
		
		//count 구하기
		count = 0;
		for(j=0; j<arr_size; j++) {
			if(avg < arr_score[j])
				count++;
		}
		
		printf("%0.3lf%%\n", ((double)count/arr_size)*100);
	}
	
	return 0;
}