
#include <stdio.h>
#include <math.h>
#define BOUND 0.0001 // 원의 중심과 직선 사이의 거리(distance)와 원의 반지름 r의 차이가 0보다는 크고 0.0001보다는 작을 때 두 함수가 접한다고 가정함. 

void getDataOfLine(double *a, double *b); //직선의 방정식에 관한 데이터를 얻는 함수
void getDataOfCircle(double *c, double *d, double *r); //원의 방정식에 관한 데이터를 얻는 함수
double Distance(double a,double b,double c,double d,double r); //원의 중심과 직선 사이의 거리를 구하는 함수
void FindtheXcoordinates(double a, double b, double c, double d, double r, double *x1, double *x2); //두 함수의 교점의 x좌표를 찾는 함수 
 
int main(void) {
	double a, b, c, d, r;
	double distance=0;
	double x1, x2; //두 함수의 교점의 x좌표들
	double y1 = 0, y2 = 0; //두 함수의 교점의 y좌표들

	getDataOfLine(&a, &b);
	getDataOfCircle(&c, &d, &r);

	distance = Distance(a, b, c, d, r);

	FindtheXcoordinates(a, b, c, d, r, &x1, &x2);

	if (distance < r) // 원의 중심과 직선 사이의 거리가 반지름의 길이보다 짧을 때 두 함수는 서로 다른 두 점에서 만난다고 가정함. 
	{
		printf("\n\n두 함수에는 두 개의 교차점이 있습니다.\n");
		y1 = a * x1 + b;
		y2 = a * x2 + b;
		printf("두 함수의 교점의 좌표는 (%.3lf,%.3lf), (%.3lf,%.3lf)입니다.\n\n", x1, y1, x2, y2);
	
	}
	else if (fabs(distance - r) < BOUND) // 원의 중심과 직선 사이의 거리(distance)와 원의 반지름 r의 차이가 -0.0001보다는 크고 0.0001보다는 작을 때 두 함수가 접한다고 가정함. 
	{
		printf("\n\n두 함수는 서로 접합니다.\n");
		y1 = a * x1 + b;
		printf("두 함수의 교점의 좌표는 (%.3lf,%.3lf)입니다.\n\n", x1, y1);
	}
	else 
		printf("\n\n두 함수의 교차점이 없습니다.\n\n");

	return 0;
}

void getDataOfLine(double *a, double *b) {
	printf("\n직선의 함수식을 입력하기 바랍니다.\n y = ax + b\n");
	printf("기울기 a = ");
	scanf("%lf", a);
	printf("y절편 b = ");
	scanf("%lf", b);
	return;
}

void getDataOfCircle(double *c, double *d, double *r) {
	printf("\n\n원의 함수식을 입력하기 바랍니다.\n (x - cx)^2 + (y - cy)^2 = r^2\n");
	printf("원의 중심의 x좌표 cx = "); //cx=c
	scanf("%lf", c);
	printf("원의 중심의 y좌표 cy = "); //cy=d
	scanf("%lf", d);
	printf("원의 반지름 r = ");
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
	newA = pow(a, 2) + (double)1;//두 함수를 연립한 방정식 (a^2+1)x^2+2(a(b-d)-c)x+(c^2+(b-d)^2-r^2)=0 
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