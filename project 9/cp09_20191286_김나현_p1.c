#include <stdio.h>

int main(void) {
	int a;
	int b;
	int r;
	int* pa = &a;
	int* pb = &b;
	int *pr = &r;
	
	printf("Enter the first number: ");
	scanf("%d", pa);
	printf("Enter the second number: ");
	scanf("%d", pb);

	*pr = *pa + *pb;
	printf("\n%d + %d is %d", *pa, *pb, *pr);
	*pr = *pa - *pb;
	printf("\n%d - %d is %d", *pa, *pb, *pr);
	*pr = *pa * *pb;
	printf("\n%d * %d is %d", *pa, *pb, *pr);
	*pr = *pa / *pb;
	printf("\n%d / %d is %d", *pa, *pb, *pr);
	*pr = *pa % *pb;
	printf("\n%d %% %d is %d", *pa, *pb, *pr); 
	printf("\n\n");

	return 0;
}