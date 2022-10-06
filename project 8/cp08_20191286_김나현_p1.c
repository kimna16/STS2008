#include <stdio.h>
#define rows 10
#define columns 2

void sorting(int originaltable[][columns], int sortedtable[][columns]);

int main(void) {
	int originaltable[rows][columns] = { {18,90},{237,47},{35,105},{5,25},{76,739},{103,26},{189,38},{22,110},{156,31},{49,245} };
	int sortedtable[rows][columns];

	printf("\nOriginal Table\n");
	for (int i = 0; i < rows; i++) {
		printf("id number: %3d, mark: %3d\n", originaltable[i][0], originaltable[i][1]);
	}

	sorting(originaltable, sortedtable);

	printf("\nAscending sorted table for the first column is as follows.\n");
	for (int j = 0; j < rows; j++) {
		printf("id number: %3d, mark: %3d\n", sortedtable[j][0], sortedtable[j][1]);
	}
	return 0;
}
void sorting(int originaltable[][columns], int sortedtable[][columns]) {
	int smallest;  
	int i, j;
	int temID, temMark;

	for (i = 0; i < rows; i++) {
		smallest = i;
		for (j = i + 1; j < rows; j++) {
			if (originaltable[smallest][0] > originaltable[j][0]) {
				smallest = j;
			}
		}
		
		if (i != smallest) {
			temID = originaltable[i][0];
			temMark = originaltable[i][1];
			originaltable[i][0] = originaltable[smallest][0];
			originaltable[i][1] = originaltable[smallest][1];
			originaltable[smallest][0] = temID;
			originaltable[smallest][1] = temMark;
		}
		
	}

	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			sortedtable[i][j] = originaltable[i][j];
		}
	}

	return;
}