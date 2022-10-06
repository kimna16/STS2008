#include <stdio.h>

void inverseOrder(int* arr, int arrSize);

int main(void) {
	int data[4][8] = { {838,758,113,515,51,627,10,419},
		{212,86,749,767,84,60,225,543},
		{89,183,137,566,966,978,495,311},
		{367,54,31,145,882,736,524,505} }; //2���� integer �迭 data�� �����ϰ� �ʱ�ȭ��. 
	int i, j; 
	int row; //reorder�ϰ� ���� �迭�� �� ��ȣ (0~3) (����ڷκ��� �� ��ȣ�� �Է� ����.)
	int scan; //EOF�� �Է����� �� ������. 
	int NumberofRow = 4;
	int NumberofColumn = 8;
	  
	printf("\nBefore Reordering\n");
	for (i = 0; i < NumberofRow; i++) {
		for (j = 0; j < NumberofColumn; j++) {
			printf("%6d", *(*(data + i) + j));
		}
		printf("\n"); //�� row�� �� ��������� new line���� �Ѿ�� ���� row�� �����.  
	}
	printf("\n"); 

	do {
		do {
			printf("\nEnter the row index (0~3): ");
			scan = scanf("%d", &row);
			if (scan == EOF)
				break;
			else if (row >= 0 && row <= 3)
				break;

		} while (1); //�Է��� ���� 0�� 3 ���� �� �Ǵ� EOF�̸� break, �ƴϸ� ��� loop�� �ݺ���. (�� ��ȣ�� �߸� �Է��ϸ� �ٽ� �Է� ����.) 

		if (scan == EOF) 
			break; //EOF�� �Է��ϸ� loop�� ��������. 
		else { //row�� 0���� 3 ������ ���� �Է��ϸ� inverseOrder �Լ��� ���� �� ���� ��ҵ��� ������ ����� �����ϰ�, for �ݺ����� ���� �ش� ���� �����. 
			inverseOrder(*(data + row), NumberofColumn);
			for (i = 0; i < NumberofColumn; i++) {
				printf("%6d", *(*(data + row) + i));
			}
			printf("\n");
		}
	
	} while (1); //EOF�� �Է��ϸ� loop�� ��������.  
	
	printf("\nAfter Reordering\n"); //EOF�� �Է��ϸ� reorder ��, ��ü �迭�� �����. 
	for (i = 0; i < NumberofRow; i++) {
		for (j = 0; j < NumberofColumn; j++) {
			printf("%6d", *(*(data + i) + j));
		}
		printf("\n"); //�� row�� �� ��������� new line���� �Ѿ�� ���� row�� �����.  
	}
	printf("\n");

	return 0;
}
void inverseOrder(int* arr, int arrSize) { //arr�� data �迭�� 'row' ���� ù ��° �ּҰ�, arrSize�� ���� ����(=NumberofColumn=8)
	int temp1; 
	int temp2;
	int x;
	int y;

	for (x = 0; x < (arrSize / 2); x++) { 
		y = (arrSize - 1) - x;
		temp1 = *(arr + x);
		temp2 = *(arr + y); 
		*(arr + x) = temp2; //arr[x]=temp2; 
		*(arr + y) = temp1; //arr[y]=temp1;
	} //�Էµ� �� ��ȣ�� �ش��ϴ� �迭�� ��Ҹ� ������ ����� ������. 

	return; 
} 