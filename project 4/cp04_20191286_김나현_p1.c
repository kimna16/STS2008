#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int rand_max = 6;
	srand(20191286);

	int rand1, rand2, rand3,rand4, rand5,rand6, rand7, rand8, rand9, rand10;
	rand1 = (rand() % rand_max) - 5;
	rand2 = (rand() % rand_max) + 2;
	rand3 = (rand() % rand_max);
	rand4 = (rand() % rand_max) * 2 + 2;
	rand5 = (rand() % rand_max) * 10 + 1;
	rand6 = (rand() % rand_max) * (-1);
	rand7 = (rand() % rand_max) + 10;
	rand8 = (rand() % rand_max);
	rand9 = (rand() % rand_max) + 16;
	rand10 =(rand() % rand_max) * 2;

	printf("\nrand1 = %d\n", rand1);
	printf("rand2 = %d\n", rand2);
	printf("rand3 = %d\n", rand3);
	printf("rand4 = %d\n", rand4);
	printf("rand5 = %d\n", rand5);
	printf("rand6 = %d\n", rand6);
	printf("rand7 = %d\n", rand7);
	printf("rand8 = %d\n", rand8);
	printf("rand9 = %d\n", rand9);
	printf("rand10 = %d\n", rand10);

	return 0;
}