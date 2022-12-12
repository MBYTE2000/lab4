#include <iostream>
#include <math.h>
#include <conio.h>
#include <iomanip>

using namespace std;
typedef double (*uf)(double, double, int&);
void tabl(double, double, double, double, uf, uf);
double y(double, double, int&);
double s(double, double, int&);


int main()
{
    setlocale(LC_ALL, "ru");
    double a = 0.2, b = 0.8, h = 0, ep = 0;
    cout << "Нажмите 1 для автоматического ввода\n";

    if (_getch() == '1') {
        cout << "Введите е: "; cin >> ep;
        h = (b - a) / 10;
    }
    else {
        cout << "Введите a, b, h, e" << endl;
        cin >> a >> b >> h >> ep;
    }

    cout << setw(10) << "X" << setw(15) << "Y(x)" << setw(15) << "S(x)" << setw(8) << "k" << endl;
    tabl(a, b, h, ep, y, s);
    cout << endl;
    return 0;
}

void tabl(double a, double b, double h, double eps, uf fun, uf fun2)
{
    int k = 0;
    double sum = 0, sum2 = 0;
    for (double x = a; x < b + h / 2; x += h)
    {
        sum = fun(x, eps, k);
        sum2 = fun2(x, eps, k);
        cout << setw(10) << x << setw(15) << sum << setw(15) << sum2 << setw(8) << k << endl;
    }
}

double y(double x, double eps, int& k)
{
    return 2*(pow(cos(x), 2)-1);
}

double s(double x, double eps, int& k)
{
    double a = 1, c = 1, sum = 0;
    k = 1;
    while (fabs(c) > eps)
    {
        c = -2*x*2*x / ((2 * k - 1) * 2 * k);
        a *= c;
        sum += a;
        k++;
    }
    return sum;
}