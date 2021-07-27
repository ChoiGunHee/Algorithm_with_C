/**
* 2021. 07. 26
* Creater : Gunhee Choi
* Problem Number : 9375
* Title : 패션왕 신해빈

* Problem :
해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다. 예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면, 다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다. 해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?

* Input :
첫째 줄에 테스트 케이스가 주어진다. 테스트 케이스는 최대 100이다.

	- 각 테스트 케이스의 첫째 줄에는 해빈이가 가진 의상의 수 n(0 ≤ n ≤ 30)이 주어진다.
	- 다음 n개에는 해빈이가 가진 의상의 이름과 의상의 종류가 공백으로 구분되어 주어진다. 같은 종류의 의상은 하나만 입을 수 있다.
	
모든 문자열은 1이상 20이하의 알파벳 소문자로 이루어져있으며 같은 이름을 가진 의상은 존재하지 않는다.

	2
	3
	hat headgear
	sunglasses eyewear
	turban headgear
	3
	mask face
	sunglasses face
	makeup face

* Output :
각 테스트 케이스에 대해 해빈이가 알몸이 아닌 상태로 의상을 입을 수 있는 경우를 출력하시오.

	5
	3

**/

#include <stdio.h>
#include <string.h>

struct clothes {
	int count;
	char group[25];
} Clothes;

int main(void) {
	int T;
	int n;
	struct clothes clothes_data[31];
	int clothes_count;
	int result;
	int flag;
	
	char tmp_clothes_name[25];
	char tmp_clothes_group[25];
	int i, j, m;
	
	scanf("%d", &T);
	
	for(i=0; i<T; i++) {
		scanf("%d", &n);
		clothes_count = 0;
		result = 1;
		
		for(j=0; j<25; j++) {
			clothes_data[j].count = 0;
			strcpy(clothes_data[j].group, "");
		}
		
		for(j=0; j<n; j++) {
			scanf("%s %s", tmp_clothes_name, tmp_clothes_group);
			flag = 1;
			
			for(m=0; m<clothes_count; m++) {
					if( strcmp(tmp_clothes_group, clothes_data[m].group) == 0) {
						clothes_data[m].count++;
						//printf("%s\n%s\n", tmp_clothes_name, tmp_clothes_group);
						flag = 0;
						break;
				}
			}
			
			if(flag) {
				clothes_data[clothes_count].count = 1;
				strcpy(clothes_data[clothes_count].group, tmp_clothes_group);
				clothes_count++;
			}
		}
		
		for(j=0; j<clothes_count; j++) {
			result *=  clothes_data[j].count + 1;
		}
		
		printf("%d\n", result-1);
	}

	return 0;	
}