#include <stdio.h>

void getCelsius(float* a);
void CelsiusToFahrenheit(float a, float* A);
void printFahrenheit(float A);

void getFahrenheit(float* b);
void FahrenheitToCelsius(float b, float* B);
void printCelsius(float B);

int main(void) {
	float a;
	float b;
	float A; //A�� �Է� ���� ���� �µ��� ȭ�� �µ��� ��ȯ�� ��
	float B; //B�� �Է� ���� ȭ�� �µ��� ���� �µ��� ��ȯ�� �� 


	getCelsius(&a);
	CelsiusToFahrenheit(a, &A);
	printFahrenheit(A);
	getFahrenheit(&b);
	FahrenheitToCelsius(b, &B);
	printCelsius(B);
	
	return;
}
void getCelsius(float* a) {

	printf("\n���� �µ��� �Է��Ͻñ� �ٶ��ϴ�: ");
	scanf("%f", a);
	return;
}
void CelsiusToFahrenheit(float a, float* A) {
	*A = (9.0 / 5.0) * a + 32.0;
	return;
}
void printFahrenheit(float A) {
	printf("ȭ�� �µ��� %.2f �Դϴ�.\n", A);
	return;
}

void getFahrenheit(float* b) {
	printf("\nȭ�� �µ��� �Է��Ͻñ� �ٶ��ϴ�: ");
	scanf("%f", b);
	return;
}
void FahrenheitToCelsius(float b, float* B) {
	*B = (5.0 / 9.0) * (b - 32.0);
	return;
}
void printCelsius(float B) {
	printf("���� �µ��� %.2f �Դϴ�.\n", B);
	return;
}