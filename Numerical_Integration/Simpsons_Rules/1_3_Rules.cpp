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
    double oddsum = 0.0, evensum = 0.0;
    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evensum += f(x + h);
        }
        else
            oddsum += f(x + h);

        x += h;
    }

    double I = (h / 3.0) * (f(a) + 4 * oddsum + 2 * evensum + f(b));

    cout << fixed << setprecision(5);
    cout << "The Approximate value of integral is: " << I << endl;

    return 0;
}