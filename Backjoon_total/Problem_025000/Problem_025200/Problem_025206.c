/**
* 2025. 11. 20
* Creater : Gunhee Choi
* Problem Number : 25206
* Title : 너의 평점은

* Problem :
인하대학교 컴퓨터공학과를 졸업하기 위해서는, 전공평점이 3.3 이상이거나 졸업고사를 통과해야 한다. 그런데 아뿔싸, 치훈이는 깜빡하고 졸업고사를 응시하지 않았다는 사실을 깨달았다!
치훈이의 전공평점을 계산해주는 프로그램을 작성해보자.
전공평점은 전공과목별 (학점 × 과목평점)의 합을 학점의 총합으로 나눈 값이다.
인하대학교 컴퓨터공학과의 등급에 따른 과목평점은 다음 표와 같다.

A+	4.5
A0	4.0
B+	3.5
B0	3.0
C+	2.5
C0	2.0
D+	1.5
D0	1.0
F	0.0
P/F 과목의 경우 등급이 P또는 F로 표시되는데, 등급이 P인 과목은 계산에서 제외해야 한다.

과연 치훈이는 무사히 졸업할 수 있을까?

* Input :
20줄에 걸쳐 치훈이가 수강한 전공과목의 과목명, 학점, 등급이 공백으로 구분되어 주어진다.

    ObjectOrientedProgramming1 3.0 A+
    IntroductiontoComputerEngineering 3.0 A+
    ObjectOrientedProgramming2 3.0 A0
    CreativeComputerEngineeringDesign 3.0 A+
    AssemblyLanguage 3.0 A+
    InternetProgramming 3.0 B0
    ApplicationProgramminginJava 3.0 A0
    SystemProgramming 3.0 B0
    OperatingSystem 3.0 B0
    WirelessCommunicationsandNetworking 3.0 C+
    LogicCircuits 3.0 B0
    DataStructure 4.0 A+
    MicroprocessorApplication 3.0 B+
    EmbeddedSoftware 3.0 C0
    ComputerSecurity 3.0 D+
    Database 3.0 C+
    Algorithm 3.0 B0
    CapstoneDesigninCSE 3.0 B+
    CompilerDesign 3.0 D0
    ProblemSolving 4.0 P

* Output :
치훈이의 전공평점을 출력한다.
정답과의 절대오차 또는 상대오차가 \(10^{-4}\) 이하이면 정답으로 인정한다.

	3.284483

**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char subject[51];
    double credit, sum_credit = 0.0;
    char grade[3];
    double total_credit = 0.0;
	
    for(int i=0; i<20; i++) {
        scanf("%s %lf %s", subject, &credit, grade);
        
        if(grade[0] == 'P') {
            continue;
        }

        total_credit += credit;

        if(grade[0] == 'A' && grade[1] == '+') {
            sum_credit += credit * 4.5;
        }
        else if(grade[0] == 'A' && grade[1] == '0') {
            sum_credit += credit * 4.0;
        }
        else if(grade[0] == 'B' && grade[1] == '+') {
            sum_credit += credit * 3.5;
        }
        else if(grade[0] == 'B' && grade[1] == '0') {
            sum_credit += credit * 3.0;
        }
        else if(grade[0] == 'C' && grade[1] == '+') {
            sum_credit += credit * 2.5;
        }
        else if(grade[0] == 'C' && grade[1] == '0') {
            sum_credit += credit * 2.0;
        }
        else if(grade[0] == 'D' && grade[1] == '+') {
            sum_credit += credit * 1.5;
        }
        else if(grade[0] == 'D' && grade[1] == '0') {
            sum_credit += credit * 1.0;
        }
    }

    printf("%.6lf\n", sum_credit/total_credit);

	return 0;	
}