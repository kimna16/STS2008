#include <stdio.h>
#include <stdlib.h>

int** transpose(int** matrix, int m, int n); //��ġ�ϰ� ���� ����� ���� m����, ���� n���� �Է���. (m�� ��ġ����� ��, n�� ��ġ����� ���� ��.)
void printMatrix(int** matrix, int m, int n); //����ϰ� ���� ����� ���� m����, ���� n���� �Է���. 

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

	printf("\nseed��ȣ %d�� ������ Matrix\n", studentID);
	printMatrix(matrix, row, column);

	transposedMatrix = transpose(matrix, row, column);

	printf("\nTranspose�� Matrix\n");
	printMatrix(transposedMatrix, column, row); //transposedMatrix�� row�� ���� matrix�� column�� ����, transposedMatrix�� column�� ���� matrix�� row�� ����.  

	free(matrix);
	free(transposedMatrix);
	return 0;
}
void printMatrix(int** matrix, int m, int n) { //m�� ����� ����� row, n�� ����� ����� column 
	int i, j;

	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}

	return;
}
int** transpose(int** matrix, int m, int n) { //m�� transpose�ϰ� ���� matrix�� row(��ġ����� ��), n�� transpose�ϰ� ���� matrix�� column(��ġ����� ��)
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