#include <bits/stdc++.h>
using namespace std;

double f(double val)
{
    return (val * val + 1);
}
int main()
{
    double a, b;
    int n;

    cout << "Enter the interval(a-->b):\n";
    cin >> a >> b;

    cout << "Enter the number of subintervals:\n";
    cin >> n;

    double sum = 0.0;
    double x = a;
    double h = (b - a) / n;

    for (int i = 0; i < n; i++)
    {
        double pre_x = x;
        x += h;

        sum += f((pre_x + x) / 2.0);
    }
    double I = h * sum;
    cout << fixed << setprecision(5);
    cout << "The Approximate value of intregral is: " << I << endl;

    return 0;
}