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

	int dividend; //나누어지는 수 
	int divisor; //나누는 수 
	int remainder; //나머지

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
		dividend = divisor; //나누는 수가 다시 나누어지는 수가 됨.
		divisor = remainder; //나머지가 다시 나누는 수가 됨.
	} while (divisor != 0); 

	*gcd = dividend; //유클리디안 호제법에 의해 divisor이 0일 때의 dividend가 최대공약수임.
	*lcm = (num1 * num2) / (*gcd);

	return;
}
