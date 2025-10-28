#include <bits/stdc++.h>
using namespace std;

double f(double val)
{
    return 1 / (1 + val * val);
}
int main()
{
    double a, b;
    int n;

    cout << "Enter the interval(a-->b) of given function: \n";
    cin >> a >> b;

    cout << "Enter the number of even subinterval:\n";
    cin >> n;

    double h = (b - a) / (double)n; // h-->step size

    double x = a;
    double sum = 0.0, sum3 = 0.0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            sum3 += f(x + h);
        }
        else
            sum += f(x + h);

        x += h;
    }

    double I = (3 * h / 8.0) * (f(a) + 3 * sum + 2 * sum3 + f(b));

    cout << fixed << setprecision(5);
    cout << "The Approximate value of integral is: " << I << endl;

    return 0;
}