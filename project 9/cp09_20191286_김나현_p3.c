#include <stdio.h>

int getTime(long time[], int max_size);
void secToHours(long time, int* hours, int* minutes, int* seconds);


int main(void) {
	int max_size = 10; // �ִ� �Է� �޴� �ð��� ����
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
		printf("��ȯ�� �ð��� �Է��Ͻñ� �ٶ��ϴ�. ");
		scanf("%ld", &enteredtime);
		time[i] = enteredtime;
		if (time[i] == 0)
			break;
	}
	if (time[i] == 0)
		return i; //0�� �����ϰ� i���� �Է��� ����.
	else
		return max_size; //max_size���� �Է��� ��� ����. 

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