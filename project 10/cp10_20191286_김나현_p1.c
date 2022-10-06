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
		printf("\n라인 당 출력하는 개수: "); 
		scanf("%d", &column); 
		if (column > 0)
			break;
	} while (1); //라인 당 출력하는 element의 개수(>0)를 column에 저장함. 

	arr = input_integer(&arrSize); //arr는 입력된 배열의 주소값, arrSize는 정수 배열의 크기
	printf("\n입력한 정수 배열 data: \n");
	printf_array(arr, arrSize, column);  //입력한 정수 배열을 라인 당 출력 숫자를 column 개에 맞춰서 출력함.  

	sort_reorder(arr, arrSize);
	printf("\n크기 순서에 따라 sort된 정수 배열 data: \n");
	printf_array(arr, arrSize, column); //크기 순서에 따라 sort한 정수 배열을 라인 당 출력 숫자를 column 개에 맞춰서 출력함.  

	free(arr);
	return 0;
}
int* input_integer(int* arrSize) {
	int* arr;

	do {
		printf("\n입력할 정수 배열의 크기: "); //입력할 총 element의 개수 
		scanf("%d", arrSize);
		if (*arrSize > 0) 
			break;
	
	} while (1);

	arr = (int*)malloc(*arrSize * sizeof(int)); 

	printf("\n%d 개의 정수를 입력하시오.(%d 개 이상의 정수를 입력해도 배열에는 %d 개의 정수만이 저장됨.)\n", *arrSize, *arrSize, *arrSize); 
	for (int i = 0; i < *arrSize; i++) { //arrSize 개보다 많은 수의 정수를 입력해도 arrSize 개 정수만을 배열에 저장함. 
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
} //입력 받은 배열을 큰 정수부터 내림차순으로 sort하는 함수 
void printf_array(int* arr, int arrSize, int lineNo) { //arrSize는 입력한 정수 배열의 크기, lineNo은 라인 당 출력하는 element의 개수 
	int i;
	
	for (i = 0; i < arrSize; i++) {
		printf("%5d", *(arr + i));
		if (i % lineNo == (lineNo - 1)) //i를 lineNo로 나누었을 때, 나머지가 (lineNo-1)이면 new line으로 넘어감. 
			printf("\n");
	}
	printf("\n");
	return; 
}