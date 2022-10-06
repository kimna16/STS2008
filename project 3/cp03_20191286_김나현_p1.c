#include <stdio.h>
#define radian 57.295779

int main(void) {

	float degree;
	float radians;

	printf("\nEnter the angle in radians: ");
	scanf("%f", &radians);

	degree =(float)(radians * radian);
	printf("%5.3f radians is %.3f degree\n", radians, degree);
	return 0;
}