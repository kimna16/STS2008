#include <stdio.h>

int getOption(void);
void getData(int* num1, int* num2);
float calc(int option, int num1, int num2);
float add(int num1, int num2); //µ¡¼À
float sub(int num1, int num2); //»¬¼À
float mul(int num1, int num2); //°ö¼À
float dvd(int num1, int num2); //³ª´°¼À
void PrintResults(int num1, int num2, int option, float result, char* stdName, int stdID);


int main()
{
	int stdID;
	char stdName[ 10 ];
	int option;
	int num1;
	int num2;
	float result;

	printf("\n¼º¸í:");
	scanf_s("%s", stdName,10);
	printf("ÇÐ¹ø:");
	scanf("%d", &stdID);

	option = getOption();
	if (option != 0)
	{
		getData(&num1, &num2);
		result = calc(option, num1, num2);
		PrintResults(num1, num2, option, result, &stdName, stdID);
	}
	return 0;
}
int getOption(void) {
	int option;
	printf("\n\t******************************");
	printf("\n\t*                            *");
	printf("\n\t*            MENU            *");
	printf("\n\t*         1. ADD             *");
	printf("\n\t*         2. SUBTRACT        *");
	printf("\n\t*         3. MULTIPLY        *");
	printf("\n\t*         4. DIVIDE          *");
	printf("\n\t*                            *");
	printf("\n\t******************************");

	printf("\n\nPlease type your choice and the key return: ");
	scanf("%d", &option);

	switch (option)
	{
	case 1: option = 1;
		break;
	case 2: option = 2;
		break;
	case 3: option = 3;
		break;
	case 4: option = 4;
		break;
	default: 
		printf("Chosen option is not valid\n");
		option = 0;
		break;
	}
	return option;
}
void getData(int* num1, int* num2) {
	printf("Please enter two integer numbers: ");
	scanf("%d %d", num1, num2);
	return;
}
float calc(int option, int num1, int num2) {
	float result;

		switch (option)
		{
		case 1: result = add(num1, num2);
			break;
		case 2: result = sub(num1, num2);
			break;
		case 3: result = mul(num1, num2);
			break;
		case 4: result = dvd(num1, num2);
			break;
		default: printf("\nOption not available");
			exit(100);
		}
	return result;
}
float add(int num1, int num2) {
	float addresult;
	addresult = (float)num1 + (float)num2;
	return addresult;
}
float sub(int num1, int num2) {
	float subresult;
	subresult = (float)num1 - (float)num2;
	return subresult;
}
float mul(int num1, int num2) {
	float mulresult;
	mulresult = (float)num1 * (float)num2;
	return mulresult;
}
float dvd(int num1, int num2) {
	float dvdresult; 

	switch (num2)
	{
	case 0: 
		printf("Error: Division by zero\n");
		dvdresult = 0;
		break;
	default: dvdresult = (float)num1 / (float)num2;
		break;
	}
	return dvdresult;
}
void PrintResults(int num1, int num2, int option, float result, char* stdName, int stdID){

	printf("\nPrinted at ÇÔ¼ö\n");
	printf("¼º¸í=%s\tÇÐ¹ø=%8d\n", stdName, stdID);
	
		switch (option)
		{
		case 1: printf("%d + %d = %.2f\n", num1, num2, result);
			break;
		case 2: printf("%d - %d = %.2f\n", num1, num2, result);
			break;
		case 3: printf("%d * %d = %.2f\n", num1, num2, result);
			break;
		case 4: 
			if (result != 0)
				printf("%d / %d = %.2f\n", num1, num2, result);
			else
				printf("Division by zero cannot be calculated\n");
			break;
		}
	return;
}