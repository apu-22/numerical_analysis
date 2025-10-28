#include <bits/stdc++.h>
using namespace std;

double f(double val)
{
    return 1 / val;
}
int main()
{
    double a, b;
    int n;

    cout << "Enter the interval(a-->b) of given function: \n";
    cin >> a >> b;

    cout << "Enter the number of subinterval:\n";
    cin >> n;

    double h = (b - a) / (double)n; // h-->step size

    double x = a;
    double sum = 0.0;
    for (int i = 1; i < n; i++)
    {
        sum += f(x + h);
        x+=h;
    }

    double I = (h / 2) * (f(a) + 2 * sum + f(b));

    cout << fixed << setprecision(5);
    cout << "The Approximate value of integral is: " << I << endl;

    return 0;
}