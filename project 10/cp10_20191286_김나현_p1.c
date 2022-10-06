#include <stdio.h>
#include <stdlib.h>

int* input_integer(int *arrSize);
void sort_reorder(int* arr, int arrSize);
void printf_array(int* arr, int arrSize, int lineNo);

int main(void) {
	int arrSize; 
	int* arr = NULL; 
	int column;
	
	do {
		printf("\n���� �� ����ϴ� ����: "); 
		scanf("%d", &column); 
		if (column > 0)
			break;
	} while (1); //���� �� ����ϴ� element�� ����(>0)�� column�� ������. 

	arr = input_integer(&arrSize); //arr�� �Էµ� �迭�� �ּҰ�, arrSize�� ���� �迭�� ũ��
	printf("\n�Է��� ���� �迭 data: \n");
	printf_array(arr, arrSize, column);  //�Է��� ���� �迭�� ���� �� ��� ���ڸ� column ���� ���缭 �����.  

	sort_reorder(arr, arrSize);
	printf("\nũ�� ������ ���� sort�� ���� �迭 data: \n");
	printf_array(arr, arrSize, column); //ũ�� ������ ���� sort�� ���� �迭�� ���� �� ��� ���ڸ� column ���� ���缭 �����.  

	free(arr);
	return 0;
}
int* input_integer(int* arrSize) {
	int* arr;

	do {
		printf("\n�Է��� ���� �迭�� ũ��: "); //�Է��� �� element�� ���� 
		scanf("%d", arrSize);
		if (*arrSize > 0) 
			break;
	
	} while (1);

	arr = (int*)malloc(*arrSize * sizeof(int)); 

	printf("\n%d ���� ������ �Է��Ͻÿ�.(%d �� �̻��� ������ �Է��ص� �迭���� %d ���� �������� �����.)\n", *arrSize, *arrSize, *arrSize); 
	for (int i = 0; i < *arrSize; i++) { //arrSize ������ ���� ���� ������ �Է��ص� arrSize �� �������� �迭�� ������. 
		scanf("%d", (arr + i)); 
	}

	return arr;
}
void sort_reorder(int* arr, int arrSize) { 
	int current;
	int biggest;
	int walk;
	int temp;
	
	for (current = 0; current < arrSize - 1; current++) { 
		biggest = current;
		for (walk = current + 1; walk < arrSize; walk++) {
			if ((*(arr + walk)) > (*(arr + biggest))) 
				biggest = walk;
		}
		temp = *(arr + current);
		*(arr + current) = *(arr + biggest);
		*(arr + biggest) = temp;
	}

	return;
} //�Է� ���� �迭�� ū �������� ������������ sort�ϴ� �Լ� 
void printf_array(int* arr, int arrSize, int lineNo) { //arrSize�� �Է��� ���� �迭�� ũ��, lineNo�� ���� �� ����ϴ� element�� ���� 
	int i;
	
	for (i = 0; i < arrSize; i++) {
		printf("%5d", *(arr + i));
		if (i % lineNo == (lineNo - 1)) //i�� lineNo�� �������� ��, �������� (lineNo-1)�̸� new line���� �Ѿ. 
			printf("\n");
	}
	printf("\n");
	return; 
}