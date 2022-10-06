
#include <stdio.h>
#include <math.h>

int getData(void);
int primefactorization(int value);

int main(void) {
	int value=0;
	value=getData();
	int NumberOfPrime;
	if (value == 0)
		return 0;
	else
	{
		NumberOfPrime = primefactorization(value);
		if (NumberOfPrime == 1)
			printf("\nIt is a prime number!\n\n");
		else
			printf("\nIt is a composite number!\n\n");
	}	
	return 0;
}

int getData(void) {
	int value;
	do
	{
		printf("\nInput an positive integer: ");
		scanf("%d", &value);
		if (value == 0) //소인수 분해할 정수에 0을 입력하면 프로그램을 종료함.
		{
			printf("\nEnd of the program\n");
			break;
		}
		else if (value<=2)
		{
			printf("%d = \n", value);
			printf("It is an invalid number!\n");
		}
	} while (value <= 2); //2보다 작은 정수를 입력하면 다시 입력 받음.
	return value;
}

int primefactorization(int value) {
	int i;
	int NumberOfPrime = 0; //소인수의 개수 
	for (i = 2; i <= value; i++)
	{
		if (value % i == 0)
			break;

	}
	if (i == value) // 소수인 value는 1과 자기 자신 이외의 소인수를 가지고 있지 않음. 
	{
		NumberOfPrime = 1; 
		printf("%d = %d", value, value);
	}
	else
	{
		int i;
		int j;
		int k = 0;
		int firstvalue = value;

		printf("%d = ", value);

		for (i=2; i<firstvalue;i++) {
			for (j = 2; i >= j; j++)
			{
				if (i % j == 0)
					break;
			}
			if (j == i)
			{
				while (value % i == 0) {
					value = value / i;
					k++;
				}
				NumberOfPrime = NumberOfPrime + k;
				if (k != 0)//k가 0이면 소인수가 없으므로 쓸 필요가 없음.
				{
					if (k == 1)
						printf("%d", i);
					else
						printf("%d^%d", i, k);

					if (value != 1) //더 이상 다른 소수로 소인수 분해가 되지 않으면 * 기호가 필요 없음. 
						printf("*");
					else
						break; 
				}
				k = 0; //k=0으로 리셋해줘야 함. 
			}
		} 
	}
	return NumberOfPrime;
}

	


	







