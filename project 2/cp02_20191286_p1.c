/* Written by: 20191286 �質��
   Date: 2020-09-10 */

#include <stdio.h>

int main(void)
{
	int year, month, day;

	printf("\nó�� ��¥�� �Է��ϱ� �ٶ��ϴ�:");
	scanf_s("%d-%d-%d", &year, &month, &day);
	printf("\n\n\t\t\tó������:%d��%d��%d��\n\n", year, month, day);

	printf("\t��ǰ��ȣ\t���\t\t�ֹ���\t\t  ����\n");
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 31235, 22, 86, 45.62);
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 3321, 55, 21, 122.0);
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 28764, 0, 24, 0.75);
	printf("\t %06d\t\t%5d\t\t%4d\t\t$ %6.2f\n", 3232, 12, 0, 10.91);

	printf("\n\tEnd of Report\n");
	printf("\t***************\n");
	printf("\t*�а�:�����а�*\n");
	printf("\t*����:�質��  *\n");
	printf("\t*�й�:20191286*\n");
	printf("\t***************");

	return 0;
}