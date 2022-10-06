#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int m, int n); //전치하고 싶은 행렬의 행을 m으로, 열을 n으로 입력함. (m은 전치행렬의 열, n은 전치행렬의 행이 됨.)
void printMatrix(int** matrix, int m, int n); //출력하고 싶은 행렬의 행을 m으로, 열을 n으로 입력함. 

int main(void) {
	int studentID = 20191286;
	int row;
	int column;
	int** matrix;
	int** transposedMatrix;

	printf("\nNumber of Rows: ");
	scanf("%d", &row);
	printf("Number of Columns: ");
	scanf("%d", &column);

	matrix = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * column);
	}

	srand(studentID);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			matrix[i][j] = rand() % 100 + 1;
		}
	}

	printf("\nseed번호 %d로 생성된 Matrix\n", studentID);
	printMatrix(matrix, row, column);

	transposedMatrix = transpose(matrix, row, column);

	printf("\nTranspose된 Matrix\n");
	printMatrix(transposedMatrix, column, row); //transposedMatrix의 row는 본래 matrix의 column과 같고, transposedMatrix의 column은 본래 matrix의 row와 같음.  

	free(matrix);
	free(transposedMatrix);
	return 0;
}
void printMatrix(int** matrix, int m, int n) { //m은 출력할 행렬의 row, n은 출력할 행렬의 column 
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}

	return;
}
int** transpose(int** matrix, int m, int n) { //m은 transpose하고 싶은 matrix의 row(전치행렬의 열), n은 transpose하고 싶은 matrix의 column(전치행렬의 행)
	int** transposedMatrix;

	transposedMatrix = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		transposedMatrix[i] = (int*)malloc(sizeof(int) * m);
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			transposedMatrix[j][i] = matrix[i][j];
		}
	}

	return transposedMatrix;
}