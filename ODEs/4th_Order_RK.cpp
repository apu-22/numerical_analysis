#include <bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return (-2 * x * x * x + 12 * x * x - 20 * x + 8.5);
}
int main()
{
    double x0, y0, xt, h;

    cout << "Enter the inital value of x & y is: \n";
    cin >> x0 >> y0;

    cout << "Enter the value of step size:\n";
    cin >> h;

    cout << "ENter the value of target of x: \n";
    cin >> xt;

    cout << fixed << setprecision(4);
    cout << "Step\tX\tY\n";
    cout << 0 << "\t" << x0 << "\t" << y0 << endl;

    double x = x0, y = y0;
    int n = (int)((xt - x) / h);
    for (int i = 1; i <= n; i++)
    {
        double k1 = f(x, y);
        double k2 = f(x + 0.5 * h, y + 0.5 * k1 * h);
        double k3 = f(x + 0.5 * h, y + 0.5 * k2 * h);
        double k4 = f(x + h, y + k3 * h);

        y = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);

        // double k1 = h * f(x, y);
        // double k2 = h * f(x + 0.5 * h, y + 0.5 * k1);
        // double k3 = h * f(x + h, y - k1 + 2 * k2);

        // y = y + (1.0 / 6.0) * (k1 + 4 * k2 + k3);

        x += h;

        cout << i << "\t" << x << "\t" << y << endl;
    }

    cout << "The Approximate value of y at x = " << xt << " is: " << y << endl;
    return 0;
}