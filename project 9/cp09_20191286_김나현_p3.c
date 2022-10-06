#include <stdio.h>

int getTime(long time[], int max_size);
void secToHours(long time, int* hours, int* minutes, int* seconds);


int main(void) {
	int max_size = 10; // 최대 입력 받는 시간의 개수
	long time[10] = { 0 }; 
	int hours, minutes, seconds;
	int NumberOfTime;

	NumberOfTime = getTime(time, max_size);

	for (int i = 0; i < NumberOfTime; i++) {
		secToHours(time[i], &hours, &minutes, &seconds);
		printf("%1ld=%2d:%02d:%02d\n", time[i], hours, minutes, seconds);
	}

	printf("\nE N D   O F   P R O G R A M\n\n");

	return 0;
}
int getTime(long time[], int max_size) { 
	long enteredtime;
	int i;

	for (i = 0; i < max_size; i++) {
		printf("변환할 시간을 입력하시기 바랍니다. ");
		scanf("%ld", &enteredtime);
		time[i] = enteredtime;
		if (time[i] == 0)
			break;
	}
	if (time[i] == 0)
		return i; //0을 제외하고 i개의 입력을 받음.
	else
		return max_size; //max_size개의 입력을 모두 받음. 

}
void secToHours(long time, int* hours, int* minutes, int* seconds) {
	long localTime;
	localTime = time;

	*seconds = (int)(localTime % (long)60);
	localTime = localTime / (long)60;
	*minutes = (int)(localTime % (long)60);
	*hours = (int)(localTime / (long)60);

	return;
}