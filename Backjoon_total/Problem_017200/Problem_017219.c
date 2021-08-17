/**
* 2021. 08. 15
* Creater : Gunhee Choi
* Problem Number : 17219
* Title : 비밀번호 찾기

* Problem :
2019 HEPC - MAVEN League의 "비밀번호 만들기"와 같은 방식으로 비밀번호를 만든 경민이는 한 가지 문제점을 발견하였다. 비밀번호가 랜덤으로 만들어져서 기억을 못 한다는 것이었다! 그래서 경민이는 메모장에 사이트의 주소와 비밀번호를 저장해두기로 했다. 하지만 컴맹인 경민이는 메모장에서 찾기 기능을 활용하지 못하고 직접 눈으로 사이트의 주소와 비밀번호를 찾았다. 메모장에 저장된 사이트의 수가 늘어나면서 경민이는 비밀번호를 찾는 일에 시간을 너무 많이 쓰게 되었다. 이를 딱하게 여긴 문석이는 경민이를 위해 메모장에서 비밀번호를 찾는 프로그램을 만들기로 결심하였다! 문석이를 도와 경민이의 메모장에서 비밀번호를 찾아주는 프로그램을 만들어보자.

* Input :
첫째 줄에 저장된 사이트 주소의 수 N(1 ≤ N ≤ 100,000)과 비밀번호를 찾으려는 사이트 주소의 수 M(1 ≤ M ≤ 100,000)이 주어진다.

두번째 줄부터 N개의 줄에 걸쳐 각 줄에 사이트 주소와 비밀번호가 공백으로 구분되어 주어진다. 사이트 주소는 알파벳 소문자, 알파벳 대문자, 대시('-'), 마침표('.')로 이루어져 있고, 중복되지 않는다. 비밀번호는 알파벳 대문자로만 이루어져 있다. 모두 길이는 최대 20자이다.

N+2번째 줄부터 M개의 줄에 걸쳐 비밀번호를 찾으려는 사이트 주소가 한줄에 하나씩 입력된다. 이때, 반드시 이미 저장된 사이트 주소가 입력된다.

	16 4
	noj.am IU
	acmicpc.net UAENA
	startlink.io THEKINGOD
	google.com ZEZE
	nate.com VOICEMAIL
	naver.com REDQUEEN
	daum.net MODERNTIMES
	utube.com BLACKOUT
	zum.com LASTFANTASY
	dreamwiz.com RAINDROP
	hanyang.ac.kr SOMEDAY
	dhlottery.co.kr BOO
	duksoo.hs.kr HAVANA
	hanyang-u.ms.kr OBLIVIATE
	yd.es.kr LOVEATTACK
	mcc.hanyang.ac.kr ADREAMER
	startlink.io
	acmicpc.net
	noj.am
	mcc.hanyang.ac.kr
	
* Output :
첫 번째 줄부터 M개의 줄에 걸쳐 비밀번호를 찾으려는 사이트 주소의 비밀번호를 차례대로 각 줄에 하나씩 출력한다.

	THEKINGOD
	UAENA
	IU
	ADREAMER

**/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NUM 1000001

typedef struct Site {
	char site[25];
	char password[25];
}Site;

Site sitelist[MAX_NUM];

int compare(const void * a, const void * b)
{
	struct Site * site1 = (struct  Site *) a;
	struct  Site * site2 = (struct Site *) b;
	
	int result = strcmp(site1->site, site2->site);
	
	if(result < 0) return -1;
	else if(result > 0) return 1;

    return result;
}

int binary_search(char * str, int low, int high) {
	int mid;
	int tmp;
	
	while (low <= high) {
		mid = (low + high) / 2;
		tmp = strcmp(str, sitelist[mid].site);
		if(!tmp) return mid;
		else if(tmp>0) low = mid + 1;
		else high = mid - 1;
	}
	
	return -1;
}

int main(void) {
	int N, M;
	char tmp_site[25];
	int i;
	
	scanf("%d %d", &N, &M);
	
	for(i=0; i<N; i++)
		scanf("%s %s", sitelist[i].site, sitelist[i].password);
	
	qsort(sitelist, N, sizeof(Site), compare);
	
	for(i=0; i<M; i++) {
		scanf("%s", tmp_site);
		printf("%s\n", sitelist[binary_search(tmp_site, 0, N)].password);
	}
	return 0;	
}