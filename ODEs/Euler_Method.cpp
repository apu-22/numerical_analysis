#include <bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    return 2*x;
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
    cout << "0\t" << x0 << "\t" << y0 << endl;
    double x = x0, y = y0;

    for (int i = 1; i <= n; i++)
    {
        y = y + h * fun(x, y);
        x += h;

        cout << i << "\t" << x << "\t" << y << endl;
    }

    cout << "Approximate value of y at x =" << xt << " is: " << y << endl;
}