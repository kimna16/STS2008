#include <stdio.h>

void getData(int* a, int* b);
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);

int main(void) {
	int a;
	int b;

	getData(&a, &b);
	add(a, b);
	subtract(a, b);
	multiply(a, b);
	divide(a, b);

	return 0;
}
void getData(int* a, int* b) {
	
	printf("\nPlease enter two integer numbers:");
	scanf("%d %d", a, b);
	return;
}
void add(int a, int b) {
	int add_result;
	add_result = a + b;
	printf("���� ����� : %d + %d = %d\n", a, b, add_result);
	return;
}
void subtract(int a, int b) {
	int subtract_result;
	subtract_result = a - b;
	printf("���� ����� : %d - %d = %d\n", a, b, subtract_result);
	return;
}
void multiply(int a, int b) {
	int multiply_result;
	multiply_result = a * b;
	printf("���� ����� : %d * %d = %d\n", a, b, multiply_result);
	return;
}
void divide(int a, int b) {
	int quotient, remainder;
	quotient = a / b;
	remainder = a % b;
	printf("���� ���� ��: %d / %d = %d\n", a, b, quotient);
	printf("������ ���� : %d %% %d = %d\n", a, b, remainder);
	return;
}
