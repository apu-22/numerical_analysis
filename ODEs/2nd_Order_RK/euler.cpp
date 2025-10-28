#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return x + y;
}

double euler(double x, double y, double h)
{
    return y + h * f(x, y);
}
int main()
{
    double x0, y0, xt, h;

    cout << "Enter the initial valie of x and y: \n";
    cin >> x0 >> y0;
    cout << "Enter the step size: \n";
    cin >> h;

    cout << "Enter the value of x(target): \n";
    cin >> xt;

    int n = (int)((xt - x0) / h);

    cout << fixed << setprecision(4);
    cout << "Step\tX\tY\n";
    cout << "0\t" << x0 << "\t" << y0 << endl;
    double x = x0, y = y0;

    for (int i = 1; i <= n; i++)
    {
        double k1 = f(x, y);
        double k2 = f(x + h, y+k1*h);

        y = y + (h / 2) * (k1 + k2);
        x += h;

        cout << i << "\t" << x << "\t" << y << endl;
    }

    cout << "The Approximate value of y at x = " << xt << " is: " << y;

    return 0;
}