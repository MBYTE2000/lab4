#include <iostream>
#include <iomanip>
#include <math.h> 
using namespace std;


typedef double (*TFun)(double);
typedef double (*SFun)(double, int);
double fun1(double);			
double fun2(double);
double S1(double r, int n);
double S2(double r, int n);
void OutRez(TFun F, SFun S, double x, double b, double h, int n);

const double PI = 3.14;

//-------------------------------------------------
int main() {
	setlocale(LC_ALL, "ru");
	double a=0.1, b=1, h=0.1;
	int n = 100;


	puts("Введите a,b,h,n");
	//cin >> a, b, h, n;
	cout << "\n\t Function - 2*pow(cos(r-1), 2)\n";
	OutRez(fun1, S1, a, b, h, n);
	cout << "\n\t Function - pow(sin(r), 2)\n";
	OutRez(fun2, S2, a, b, h, n);
	return 0;
}

//----------------------------------------------------------------
double fun1(double r) {
	//return 2*pow(cos(r-1), 2);
	return (r*r/4 + r/2 +1)*exp(r/2);
}
double fun2(double r) {
	return exp(r * cos(PI / 4.)) * cos(r * sin(PI / 4.));
}



double S1(double r, int n) {
	double s = 1, fa=1, p=1;
	/*for (int i = 1; i <= n; i++)
	{
		fa *= i*(i+1);
		p *= -((2 * r) * (2 * r))/fa;
		s += p;
	}*/

	for (int i = 1; i <= n; i++)
	{
		p *= (r / 2) / i;
		s += (i * i + 1)*p;
	}
	return s;
}
double S2(double r, int n) {
	double s = 1, p = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= r / i;
		s += cos(i*PI / 4) * p;
	}
	return s;
}


void OutRez(TFun F, SFun S, double x, double b, double h, int n)
{
	double p, s, y, m, fa;
	do
	{
		s = S(x, n);
		y = F(x);
		m = abs(y - s);
		cout << setw(15) << x << setw(15) << y << setw(15) << s << setw(15) << m << endl;
		x += h;
	} while (x <= b + h / 2.);
	
}