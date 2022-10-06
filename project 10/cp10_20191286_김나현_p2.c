#include <stdio.h>

void inverseOrder(int* arr, int arrSize);

int main(void) {
	int data[4][8] = { {838,758,113,515,51,627,10,419},
		{212,86,749,767,84,60,225,543},
		{89,183,137,566,966,978,495,311},
		{367,54,31,145,882,736,524,505} }; //2차원 integer 배열 data를 선언하고 초기화함. 
	int i, j; 
	int row; //reorder하고 싶은 배열의 행 번호 (0~3) (사용자로부터 행 번호를 입력 받음.)
	int scan; //EOF를 입력했을 때 종료함. 
	int NumberofRow = 4;
	int NumberofColumn = 8;
	  
	printf("\nBefore Reordering\n");
	for (i = 0; i < NumberofRow; i++) {
		for (j = 0; j < NumberofColumn; j++) {
			printf("%6d", *(*(data + i) + j));
		}
		printf("\n"); //한 row를 다 출력했으면 new line으로 넘어가서 다음 row를 출력함.  
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

		} while (1); //입력한 값이 0과 3 사이 값 또는 EOF이면 break, 아니면 계속 loop를 반복함. (행 번호를 잘못 입력하면 다시 입력 받음.) 

		if (scan == EOF) 
			break; //EOF를 입력하면 loop를 빠져나옴. 
		else { //row에 0부터 3 사이의 값을 입력하면 inverseOrder 함수를 통해 행 안의 요소들의 순서를 뒤집어서 저장하고, for 반복문을 통해 해당 행을 출력함. 
			inverseOrder(*(data + row), NumberofColumn);
			for (i = 0; i < NumberofColumn; i++) {
				printf("%6d", *(*(data + row) + i));
			}
			printf("\n");
		}
	
	} while (1); //EOF를 입력하면 loop를 빠져나옴.  
	
	printf("\nAfter Reordering\n"); //EOF를 입력하면 reorder 후, 전체 배열을 출력함. 
	for (i = 0; i < NumberofRow; i++) {
		for (j = 0; j < NumberofColumn; j++) {
			printf("%6d", *(*(data + i) + j));
		}
		printf("\n"); //한 row를 다 출력했으면 new line으로 넘어가서 다음 row를 출력함.  
	}
	printf("\n");

	return 0;
}
void inverseOrder(int* arr, int arrSize) { //arr는 data 배열의 'row' 행의 첫 번째 주소값, arrSize는 열의 개수(=NumberofColumn=8)
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
	} //입력된 행 번호에 해당하는 배열의 요소를 순서를 뒤집어서 저장함. 

	return; 
} 