#include <bits/stdc++.h>

using namespace std;

int a = 1;
double b = 1.1;

int main()
{
    int * x = &a;
    double * y = &b;

    cout << x << " = " << &a << " = " << *x << endl;
    cout << y << " = " << &b <<" = " << *y << endl;


    return 0;
}