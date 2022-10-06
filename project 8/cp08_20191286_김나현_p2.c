#include <stdio.h>
#include <stdlib.h>

int getString(char string[]);
void reverseString(char string[], int sizeString);
void printString(char string[], int sizeString);


int main(void) {
	char string[250] = { 0 }; //배열 string 초기화 
	int sizeString; //배열 string의 크기 

	sizeString = getString(string);

	while (sizeString != -1) {
		reverseString(string, sizeString);
		printString(string, sizeString);
		sizeString = getString(string);
	}

	if (sizeString == -1)
		exit(100);

	return 0;
}
int getString(char string[]) {
	int ch;
	int i = 0;

	printf("\n문자열을 입력하시기 바랍니다.\n(단, 종료는 CTRL-Z): ");
	ch= getchar();
	
	while (ch != EOF && ch != '\n') {
		string[i] = ch;
		i++;
		ch = getchar();
	}

	if (ch == EOF) {
		return -1; //EOF을 입력하면 sizeString에 -1을 return 
	}
	else {
		string[i] = '\0';
		return i++; //sizeString에 \0를 제외하고 몇 개의 문자가 getchar 되었는지를 return 
	}
}
void reverseString(char string[], int sizeString) {
	int temData = 0;

	if (!(sizeString % 2)) {
		for (int i = 0; i <= (sizeString / 2) - 1; i++) {
			temData = string[i];
			string[i] = string[sizeString - 1 - i];
			string[sizeString - 1 - i] = temData;
		}
	}
	else 
		for (int j = 0; j < (sizeString - 1) / 2; j++) {
			temData = string[j];
			string[j] = string[sizeString - 1 - j];
			string[sizeString - 1 - j] = temData;
		}

	return;
}
void printString(char string[], int sizeString) {
	int ch;
	printf("역으로 배열한 문자열은: ");
	for (int i = 0; i < sizeString; i++) {
		ch = string[i];
		putchar(ch);
	}
	printf("\n");
	return;
}