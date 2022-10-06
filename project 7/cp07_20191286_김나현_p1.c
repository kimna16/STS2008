#include <stdio.h>
#include <stdlib.h>

void getData(FILE* spIn);
void classifyData(FILE* spInForReading, FILE* spOut0to30, FILE* spOut30to60, FILE* spOut60to90, FILE* spOut90to100);

int main(void) {
	FILE* spIn;
	FILE* spInForReading;
	FILE* spOut0to30; FILE* spOut30to60; FILE* spOut60to90; FILE* spOut90to100;
	int state1, state2, state3, state4, state5, state6;

	printf("\n처리 결과\n");

	spIn = fopen("integer.txt", "w");
	if (spIn != NULL) {
		getData(spIn);
		fflush(spIn);
	}
	else
	{
		printf("file open error!\n");
		exit(100);
	}
	
	spInForReading = fopen("integer.txt", "r");
	spOut0to30 = fopen("integer0to30.txt", "w");
	spOut30to60 = fopen("integer30to60.txt", "w");
	spOut60to90 = fopen("integer60to90.txt", "w");
	spOut90to100 = fopen("integer90to100.txt", "w");
	if (spOut0to30 != NULL && spOut30to60 != NULL && spOut60to90 != NULL && spOut90to100 != NULL) 
		classifyData(spInForReading, spOut0to30, spOut30to60, spOut60to90, spOut90to100);
	else 
	{
		printf("file open error!\n");
		exit(100);
	}

	state1 = fclose(spIn);
	state2 = fclose(spInForReading);
	state3 = fclose(spOut0to30);
	state4 = fclose(spOut30to60);
	state5 = fclose(spOut60to90);
	state6 = fclose(spOut90to100);

	if (state1 != 0 || state2 != 0 || state3 != 0 || state4 != 0 || state5 != 0 || state6 != 0) {
		printf("file close error!\n");
		exit(100);
	}

	return 0;
}
void getData(FILE* spIn) {
	srand(20191286);
	int i = 1;
	int j = 1;
	for (; i <= 10 && j <= 10; i++) {
		fprintf(spIn, "%d ", rand() % 100);
		if (i == 10) {
			fprintf(spIn, "\n");
			i = 0;
			j = j + 1;
			if (j == 11)
				break;
		}
	}
	return;
}
void classifyData(FILE* spInForReading, FILE* spOut0to30, FILE* spOut30to60, FILE* spOut60to90, FILE* spOut90to100) {
	int cnt_0to30 = 0;
	int cnt_30to60 = 0;
	int cnt_60to90 = 0;
	int cnt_90to100 = 0;
	int cnt_outofrange = 0;
	int sum0to30 = 0;
	int sum30to60 = 0;
	int sum60to90 = 0;
	int sum90to100 = 0;
	float avrg0to30, avrg30to60, avrg60to90, avrg90to100;
	int integer;
	int i;
	int j = 1;

	for (i = 1; i <= 10; i++) {
		fscanf(spInForReading, "%d ", &integer);
		if (integer >= 0 && integer < 30) {
			++cnt_0to30;
			sum0to30 = sum0to30 + integer;
			fprintf(spOut0to30, "%d ", integer);
		}
		else if (integer >= 30 && integer < 60) {
			++cnt_30to60;
			sum30to60 = sum30to60 + integer;
			fprintf(spOut30to60, "%d ", integer);
		}
		else if (integer >= 60 && integer < 90) {
			++cnt_60to90;
			sum60to90 = sum60to90 + integer;
			fprintf(spOut60to90, "%d ", integer);
		}
		else if (integer >= 90 && integer <= 100) {
			++cnt_90to100;
			sum90to100 = sum90to100 + integer;
			fprintf(spOut90to100, "%d ", integer);
		}
		else
			++cnt_outofrange;
		if (i == 10) {
			fscanf(spInForReading, "\n");
			i = 0;
			j++;
			if (j == 11)
				break;
		}
	}

	avrg0to30 = (float)sum0to30 / (float)cnt_0to30;
	avrg30to60 = (float)sum30to60 / (float)cnt_30to60;
	avrg60to90 = (float)sum60to90 / (float)cnt_60to90;
	avrg90to100 = (float)sum90to100 / (float)cnt_90to100;

	printf("\n0  이상 ~ 30  미만: count = %d, 평균 = %.1f\n", cnt_0to30, avrg0to30);
	printf("30 이상 ~ 60  미만: count = %d, 평균 = %.1f\n", cnt_30to60, avrg30to60);
	printf("60 이상 ~ 90  미만: count = %d, 평균 = %.1f\n", cnt_60to90, avrg60to90);
	printf("90 이상 ~ 100 이하: count = %d, 평균 = %.1f\n", cnt_90to100, avrg90to100);
	printf("\n범위 외의 숫자 count = %d\n\n", cnt_outofrange);
	return;
}