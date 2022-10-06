#include <stdio.h>

void calGcdLcm(int num1, int num2, int* gcd, int* lcm);

int main(void) {

	int num1, num2;
	int gcd, lcm;

	printf("\nEnter the 1st number: ");
	scanf("%d", &num1);
	printf("Enter the 2nd number: ");
	scanf("%d", &num2);

	calGcdLcm(num1, num2, &gcd, &lcm);

	printf("\nGCD of %d and %d is %d", num1, num2, gcd);
	printf("\nLCM of %d and %d is %d", num1, num2, lcm);
	printf("\n\n");

	return 0;
}
void calGcdLcm(int num1, int num2, int* gcd, int* lcm) {

	int dividend; //���������� �� 
	int divisor; //������ �� 
	int remainder; //������

	if (num1 > num2) {
		dividend = num1;
		divisor = num2;
	}
	else {
		dividend = num2;
		divisor = num1;
	} 

	do{ 
		remainder = dividend % divisor;
		dividend = divisor; //������ ���� �ٽ� ���������� ���� ��.
		divisor = remainder; //�������� �ٽ� ������ ���� ��.
	} while (divisor != 0); 

	*gcd = dividend; //��Ŭ����� ȣ������ ���� divisor�� 0�� ���� dividend�� �ִ�������.
	*lcm = (num1 * num2) / (*gcd);

	return;
}
