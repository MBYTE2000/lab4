#include <stdio.h>

#include <conio.h>

#include <math.h>

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused

void Out_Rez(double, double, double, double);

int main(int argc, char* argv[])

{

    double a, b, x, h, y, s;

    int n, k, fact, r;

    puts("Input a,b,h,n");

    scanf_s("%f%f%f%d", &a, &b, &h, &n);

    for (x = a; x <= b; x += h) {

        y = exp(2 * x);

        fact = 1; s = 0;

        for (k = 0; k <= n; k++) {

            if (k == 0) fact = 1;

            else fact = k;

            s += pow(2*x, k) / fact;

        }

        r = fabs(y - s);

        Out_Rez(x, y, s, r);

    }

    return 0;
}

void Out_Rez(double x, double y, double s, double r)

{

    printf("\n x= %8.2f", x);

    printf("\n Y(x)= %8.6f", y);

    printf("\n S(x)= %8.6f", s);

    printf("\n |Y(X)-S(X)|= %8.6f", r);

}