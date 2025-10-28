#include <bits/stdc++.h>
#define ll long long int
#define vamus                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
using namespace std;

double f(double x)
{
    return 4 * x * x + 3 * x - 3;
}
double fd(double x)
{
    return 8 * x + 3;
}

void newtonRafshon(double x0, double tolarence, int max_iter = 100)
{
    double x = x0;
    int it = 0;

    while (it < max_iter)
    {
        double fx = f(x);
        double fdx = fd(x);

        if (fdx == 0)
        {
            cout << "Derivative is zero. Method fails." << endl;
            return;
        }

        double x1 = x - fx / fdx;
        cout << it << "\t" << x << "\t" << fx << "\t" << fdx << "\t" << x1 << "\t" << fabs(x1 - x) << endl;

        if (fabs(x1 - x) < tolarence)
        {
            cout << "\nThe approimate root is: " << x1 << endl;
            return;
        }
        x = x1;
        it++;
    }
    cout << "Method did not converge within max iterations." << endl;
}

int main()
{
    vamus;
    double a, b, tolarence = 1e-6;
    cin >> a >> b;

    while (f(a) * f(b) >= 0)
    {
        cout << "Invalid range, please enter ahain interval: " << endl;
        cin >> a >> b;
    }
    cout << "Take initial guess: x0=a|b" << endl;
    double x0 = a;

    newtonRafshon(x0, tolarence);
    return 0;
}
