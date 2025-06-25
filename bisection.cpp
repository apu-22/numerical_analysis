#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return x * x + 3 * x - 3;
}

void bisection(double a, double b, double err)
{
    if (f(a) * f(b) >= 0)
    {
        cout << "There is no solution between the given interval or there is multiple solution.";
        return;
    }
    double c;
    int iteration = 0;

    while ((b - a) >= err)
    {
        c = (b + a) / 2;
        iteration++;
        if (c == 0.0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The root of this function is: " << c << endl;
}

int main()
{
    double a, b, err;
    cout << "Enter first interval: " << endl;
    cin >> a;
    cout << "Enter second interval: " << endl;
    cin >> b;
    cout << "Enter error : " << endl;
    cin >> err;

    bisection(a, b, err);

    return 0;
}