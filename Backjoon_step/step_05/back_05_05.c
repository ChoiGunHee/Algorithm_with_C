/**
* 2021. 02. 09
* Creater : Gunhee Choi
* Problem Number : 1546
* Title : 평균

* Problem :
세준이는 기말고사를 망쳤다. 세준이는 점수를 조작해서 집에 가져가기로 했다. 일단 세준이는 자기 점수 중에 최댓값을 골랐다. 이 값을 M이라고 한다. 그리고 나서 모든 점수를 점수/M*100으로 고쳤다.

예를 들어, 세준이의 최고점이 70이고, 수학점수가 50이었으면 수학점수는 50/70*100이 되어 71.43점이 된다.

세준이의 성적을 위의 방법대로 새로 계산했을 때, 새로운 평균을 구하는 프로그램을 작성하시오.

* Input : 첫째 줄에 시험 본 과목의 개수 N이 주어진다. 이 값은 1000보다 작거나 같다. 둘째 줄에 세준이의 현재 성적이 주어진다. 이 값은 100보다 작거나 같은 음이 아닌 정수이고, 적어도 하나의 값은 0보다 크다.
	3
	40 80 60
	
* Output : 첫째 줄에 새로운 평균을 출력한다. 실제 정답과 출력값의 절대오차 또는 상대오차가 10-2 이하이면 정답이다.
	75.0
**/

#include <stdio.h>
#include <stdlib.h>

int main() {
	int arr_num;
	int * arr_score;
	int max_score = 0;
	double * arr_results;
	double result;
	int i;
	
	//배열 개수 입력
	scanf("%d", &arr_num);
	
	//점수, 결과 입력 및 공간 할당
	arr_score = (int *) malloc(sizeof(int)*arr_num);
	arr_results = (double *) malloc(sizeof(double)*arr_num);
	for(i=0; i<arr_num; i++) {
		scanf("%d", &arr_score[i]);
	}
	
	//최대값 설정
	for(i=0; i<arr_num; i++) {
		if(max_score < arr_score[i])
			max_score = arr_score[i];
	}
	
	//평균값 설정
	result = 0;
	for(i=0; i<arr_num; i++) {
		arr_results[i] = arr_score[i]/((double)max_score)*100;
		result += arr_results[i];
	}
	
	printf("%lf\n", result/arr_num);
	
	return 0;
}