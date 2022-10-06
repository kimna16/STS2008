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
	float A; //A는 입력 받은 섭씨 온도를 화씨 온도로 변환한 값
	float B; //B는 입력 받은 화씨 온도를 섭씨 온도로 변환한 값 


	getCelsius(&a);
	CelsiusToFahrenheit(a, &A);
	printFahrenheit(A);
	getFahrenheit(&b);
	FahrenheitToCelsius(b, &B);
	printCelsius(B);
	
	return;
}
void getCelsius(float* a) {

	printf("\n섭씨 온도를 입력하시기 바랍니다: ");
	scanf("%f", a);
	return;
}
void CelsiusToFahrenheit(float a, float* A) {
	*A = (9.0 / 5.0) * a + 32.0;
	return;
}
void printFahrenheit(float A) {
	printf("화씨 온도는 %.2f 입니다.\n", A);
	return;
}

void getFahrenheit(float* b) {
	printf("\n화씨 온도를 입력하시기 바랍니다: ");
	scanf("%f", b);
	return;
}
void FahrenheitToCelsius(float b, float* B) {
	*B = (5.0 / 9.0) * (b - 32.0);
	return;
}
void printCelsius(float B) {
	printf("섭씨 온도는 %.2f 입니다.\n", B);
	return;
}