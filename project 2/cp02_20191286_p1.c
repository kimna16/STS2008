/* Written by: 20191286 김나현
   Date: 2020-09-10 */

#include <stdio.h>

int main(void)
{
	int year, month, day;

	printf("\n처리 날짜를 입력하기 바랍니다:");
	scanf_s("%d-%d-%d", &year, &month, &day);
	printf("\n\n\t\t\t처리일자:%d년%d월%d일\n\n", year, month, day);

	printf("\t부품번호\t재고량\t\t주문량\t\t  가격\n");
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 31235, 22, 86, 45.62);
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 3321, 55, 21, 122.0);
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 28764, 0, 24, 0.75);
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 3232, 12, 0, 10.91);

	printf("\n\tEnd of Report\n");
	printf("\t***************\n");
	printf("\t*학과:물리학과*\n");
	printf("\t*성명:김나현  *\n");
	printf("\t*학번:20191286*\n");
	printf("\t***************");

	return 0;
}