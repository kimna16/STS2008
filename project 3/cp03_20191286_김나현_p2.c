#include <stdio.h>

#define QUIZ_WEIGHT    30
#define MIDTERM_WEIGHT 40
#define FINAL_WEIGHT   30
#define QUIZ_MAX       400.0
#define MIDTERM_MAX    200.0
#define FINAL_MAX      100.0

int main(void) {
	//Local Declarations
	int quiz1;
	int quiz2;
	int quiz3;
	int quiz4;
	int totalQuiz;

	int midterm1;
	int midterm2;
	int totalMidterm;

	int final;

	float quizPercent;
	float midtermPercent;
	float finalPercent;
	float totalPercent;

	//Statements
	printf("\n*********** Quiz 점수 입력 ***********\n");
	printf("Enter the score for the 1st Quiz: ");
	scanf("%d", &quiz1);
	printf("Enter the score for the 2nd Quiz: ");
	scanf("%d", &quiz2);
	printf("Enter the score for the 3rd Quiz: ");
	scanf("%d", &quiz3);
	printf("Enter the score for the 4th Quiz: ");
	scanf("%d", &quiz4);

	printf("********** Midterm 점수 입력 **********\n");
	printf("Enter the score for the 1st Midterm: ");
	scanf("%d", &midterm1);
	printf("Enter the score for the 1st Midterm: ");
	scanf("%d", &midterm2);

	printf("*********** Final 점수 입력 ***********\n");
	printf("Enter the score for the final: ");
	scanf("%d", &final);

	totalQuiz = quiz1 + quiz2 + quiz3 + quiz4;
	totalMidterm = midterm1 + midterm2;

	quizPercent = (float)totalQuiz * QUIZ_WEIGHT / QUIZ_MAX;
	midtermPercent = (float)totalMidterm * MIDTERM_WEIGHT / MIDTERM_MAX;
	finalPercent = (float)final * FINAL_WEIGHT / FINAL_MAX;
	totalPercent = quizPercent + midtermPercent + finalPercent;

	printf("\n 1st Quiz %d\n 2nd Quiz %d\n 3rd Quiz %d\n 4th Quiz %d\n Quiz 점수 합계 %d\n", quiz1, quiz2, quiz3, quiz4, totalQuiz);
	printf("\n 1st Midterm %d\n 2nd Midterm %d\n 중간고사 점수 합계 %d\n", midterm1, midterm2, totalMidterm);
	printf("\n 기말고사 점수 %d\n", final);

	printf("\n Quiz \t %.1f%%\n Midterm %.1f%%\n Final \t %.1f%%\n", quizPercent, midtermPercent, finalPercent);
	printf("--------------------------------------------");
	printf("\n 최종 평균 점수  %.1f%%\n", totalPercent);

	return 0;
}

