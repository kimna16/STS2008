
#include <stdio.h>
#include <math.h>
#define BOUND 0.0001 // ���� �߽ɰ� ���� ������ �Ÿ�(distance)�� ���� ������ r�� ���̰� 0���ٴ� ũ�� 0.0001���ٴ� ���� �� �� �Լ��� ���Ѵٰ� ������. 

void getDataOfLine(double *a, double *b); //������ �����Ŀ� ���� �����͸� ��� �Լ�
void getDataOfCircle(double *c, double *d, double *r); //���� �����Ŀ� ���� �����͸� ��� �Լ�
double Distance(double a,double b,double c,double d,double r); //���� �߽ɰ� ���� ������ �Ÿ��� ���ϴ� �Լ�
void FindtheXcoordinates(double a, double b, double c, double d, double r, double *x1, double *x2); //�� �Լ��� ������ x��ǥ�� ã�� �Լ� 
 
int main(void) {
	double a, b, c, d, r;
	double distance=0;
	double x1, x2; //�� �Լ��� ������ x��ǥ��
	double y1 = 0, y2 = 0; //�� �Լ��� ������ y��ǥ��

	getDataOfLine(&a, &b);
	getDataOfCircle(&c, &d, &r);

	distance = Distance(a, b, c, d, r);

	FindtheXcoordinates(a, b, c, d, r, &x1, &x2);

	if (distance < r) // ���� �߽ɰ� ���� ������ �Ÿ��� �������� ���̺��� ª�� �� �� �Լ��� ���� �ٸ� �� ������ �����ٰ� ������. 
	{
		printf("\n\n�� �Լ����� �� ���� �������� �ֽ��ϴ�.\n");
		y1 = a * x1 + b;
		y2 = a * x2 + b;
		printf("�� �Լ��� ������ ��ǥ�� (%.3lf,%.3lf), (%.3lf,%.3lf)�Դϴ�.\n\n", x1, y1, x2, y2);
	
	}
	else if (fabs(distance - r) < BOUND) // ���� �߽ɰ� ���� ������ �Ÿ�(distance)�� ���� ������ r�� ���̰� -0.0001���ٴ� ũ�� 0.0001���ٴ� ���� �� �� �Լ��� ���Ѵٰ� ������. 
	{
		printf("\n\n�� �Լ��� ���� ���մϴ�.\n");
		y1 = a * x1 + b;
		printf("�� �Լ��� ������ ��ǥ�� (%.3lf,%.3lf)�Դϴ�.\n\n", x1, y1);
	}
	else 
		printf("\n\n�� �Լ��� �������� �����ϴ�.\n\n");

	return 0;
}

void getDataOfLine(double *a, double *b) {
	printf("\n������ �Լ����� �Է��ϱ� �ٶ��ϴ�.\n y = ax + b\n");
	printf("���� a = ");
	scanf("%lf", a);
	printf("y���� b = ");
	scanf("%lf", b);
	return;
}

void getDataOfCircle(double *c, double *d, double *r) {
	printf("\n\n���� �Լ����� �Է��ϱ� �ٶ��ϴ�.\n (x - cx)^2 + (y - cy)^2 = r^2\n");
	printf("���� �߽��� x��ǥ cx = "); //cx=c
	scanf("%lf", c);
	printf("���� �߽��� y��ǥ cy = "); //cy=d
	scanf("%lf", d);
	printf("���� ������ r = ");
	scanf("%lf", r);
	return;
}

double Distance(double a, double b, double c, double d, double r) {
	double distance;
	distance = (fabs(a * c - d + b)) / (sqrt(pow(a,2) + (double)1));
	return distance;
}

void FindtheXcoordinates(double a, double b, double c, double d, double r, double *x1, double *x2) {
	double newA,newC,halfB, HalfD;
	newA = pow(a, 2) + (double)1;//�� �Լ��� ������ ������ (a^2+1)x^2+2(a(b-d)-c)x+(c^2+(b-d)^2-r^2)=0 
	halfB = a * (b - d) - c;
	newC = pow(c, 2) + pow((b - d), 2) - pow(r, 2);
	HalfD = pow(halfB, 2) - (newA) * (newC);
	if (HalfD < 0)
		*x1 = *x2 = halfB / (2 * newA);
	else
	{
		*x1 = (((-halfB) - sqrt(HalfD)) / newA); //x1= (-halfB - root(halfB^2-newA*newC))/newA
		*x2 = (((-halfB) + sqrt(HalfD)) / newA); //x2= (-halfB + root(halfB^2-newA*newC))/newA
	}
	return;
}