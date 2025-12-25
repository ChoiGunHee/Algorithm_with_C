/**
* 2025. 12. 25
* Creater : Gunhee Choi
* Problem Number : 4470
* Title : 줄번호

* Problem :
텍스트에서 줄을 입력받은 뒤, 줄 번호를 출력하는 프로그램을 작성하시오.

* Input :
첫째 줄에 줄의 수 N이 주어진다. 둘째 줄부터 N개의 줄에 각 줄의 내용이 주어진다. 각 줄에 있는 글자의 개수는 50글자를 넘지 않는다.

    5
    Lionel Cosgrove
    Alice
    Columbus and Tallahassee
    Shaun and Ed
    Fido
	
* Output :
각 문장의 앞에 줄 번호를 추가한 뒤 출력한다. 줄 번호는 1번부터 시작한다. 줄번호를 추가하는 형식은 출력 예제를 참고하면 된다.
   
    1. Lionel Cosgrove
    2. Alice
    3. Columbus and Tallahassee
    4. Shaun and Ed
    5. Fido

**/

#include <stdio.h>

int main(void) {
    int N;
    char line[100];

    scanf("%d", &N);
    getchar();
    for (int i = 1; i <= N; i++) {
        fgets(line, sizeof(line), stdin);
        printf("%d. %s", i, line);
    }

    return 0;
}