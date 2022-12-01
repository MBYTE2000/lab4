#include <iostream>
#include <iomanip>
#include <math.h> 
using namespace std;


typedef double (*TFun)(double);
double fun1(double);			
double fun2(double);
void OutRez(TFun f, double x, double b, double h, int n);

int main() {
	setlocale(LC_ALL, "ru");
	double a=0.1, b=1, h=0.1;
	int n = 10;


	puts("Введите a,b,h,n");
	//cin >> a, b, h, n;
	cout << "\n\t Function - 2*pow(cos(r-1), 2)\n";
	OutRez(fun1, a, b, h, n);
	cout << "\n\t Function - pow(sin(r), 2)\n";
	OutRez(fun2, a, b, h, n);
	return 0;
}


double fun1(double r) {
	return 2*pow(cos(r-1), 2);
}
double fun2(double r) {
	return pow(sin(r), 2);
}


void OutRez(TFun f, double x, double b, double h, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "x=" << i << " y=" << f(x) << endl;
	}

	/*double p, s, y, m, fa;
	do
	{
		p = 1;
		s = fa = 0;
		for (int i = 1; i <= n; i++)
		{
			p *= -((2*x)*(2*x));
			fa += 2*i;
			s += p / fa;
		}
		y = f(x);
		m = abs(y - s);
		cout << setw(15) << x << setw(15) << y << setw(15) << s << setw(15) << m << endl;
		x += h;
	} while (x <= b + h / 2.);*/
}

