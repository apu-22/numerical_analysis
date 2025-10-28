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
        cout << "There is no unique root in the given interval or there might be multiple roots." << endl;
        return;
    }

    double c;
    int iteration = 0;

    cout << fixed << setprecision(6);
    cout << "\n-----------------------------------------------------------\n";
    cout << "Iter\ta\t\tb\t\tc\t\tf(c)\t\t|b-a|\n";
    cout << "-----------------------------------------------------------\n";

    while ((b - a) >= err)
    {
        c = (a + b) / 2.0;
        iteration++;

        cout << iteration << "\t" << a << "\t" << b << "\t" << c << "\t" << f(c) << "\t" << fabs(b - a) << endl;

        // If f(c) is close to 0, we found the root (or close enough)
        if (fabs(f(c)) <= err)
            break;

        // Decide the side to repeat the steps
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "\nThe approximate root of the function is: " << c << endl;
    cout << "Total iterations: " << iteration << endl;
}

int main()
{
    double a, b, err;
    cout << "Enter first interval (a): ";
    cin >> a;
    cout << "Enter second interval (b): ";
    cin >> b;
    cout << "Enter allowed error (e): ";
    cin >> err;

    bisection(a, b, err);

    return 0;
}
