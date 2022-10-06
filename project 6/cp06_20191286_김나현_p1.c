
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
		if (value == 0) //���μ� ������ ������ 0�� �Է��ϸ� ���α׷��� ������.
		{
			printf("\nEnd of the program\n");
			break;
		}
		else if (value<=2)
		{
			printf("%d = \n", value);
			printf("It is an invalid number!\n");
		}
	} while (value <= 2); //2���� ���� ������ �Է��ϸ� �ٽ� �Է� ����.
	return value;
}

int primefactorization(int value) {
	int i;
	int NumberOfPrime = 0; //���μ��� ���� 
	for (i = 2; i <= value; i++)
	{
		if (value % i == 0)
			break;

	}
	if (i == value) // �Ҽ��� value�� 1�� �ڱ� �ڽ� �̿��� ���μ��� ������ ���� ����. 
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
				if (k != 0)//k�� 0�̸� ���μ��� �����Ƿ� �� �ʿ䰡 ����.
				{
					if (k == 1)
						printf("%d", i);
					else
						printf("%d^%d", i, k);

					if (value != 1) //�� �̻� �ٸ� �Ҽ��� ���μ� ���ذ� ���� ������ * ��ȣ�� �ʿ� ����. 
						printf("*");
					else
						break; 
				}
				k = 0; //k=0���� ��������� ��. 
			}
		} 
	}
	return NumberOfPrime;
}

	


	







