#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE* input;
	FILE* output;

	int ID; //ID�� ��ǰ��ȣ
	int stock, minimumNumber, minimumOrder; //stock�� ���, minimumNumber�� ���ֹ�����, minimumOrder�� �ּ��ֹ���
	int numberOrder; //numberOrder�� �ֹ��� 
	float price; //price�� ����
	int state1, state2;
 	
	input = fopen("inputdata.txt", "r");
	output = fopen("outputdata.txt", "w");

	if (input == NULL) {
		printf("input file open error! \n");
		exit(100);
	}
	else {
		printf("\n\t\t\t Inventory Report\t\t\t\n");
		printf("    ��ǰ��ȣ    ����    ���  ���ֹ����� �ּ��ֹ��� �ֹ���\n");
		while (fscanf(input,"%d %f %d %d %d",&ID,&price,&stock,&minimumNumber,&minimumOrder) != EOF) {
			if (stock <= minimumNumber) {
				numberOrder = (minimumNumber + minimumOrder) - stock;
			}
			else
				numberOrder = 0;
			fprintf(output, "%04d %.2f %d %d %d %d\n", ID, price, stock, minimumNumber, minimumOrder, numberOrder);
			printf("      %04d%10.2f%8d%10d%11d%9d\n", ID, price, stock, minimumNumber, minimumOrder, numberOrder);
		}
	}

	state1 = fclose(input);
	state2 = fclose(output);

	if (state1 != 0 || state2 != 0) {
		printf("file close error! \n");
		exit(101);
	}

	printf("\nEnd of Report\n\n");
	return 0;
}