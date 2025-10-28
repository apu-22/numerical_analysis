
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

void falsi(double a, double b, double tol)
{
    int it = 0;
    double fa = f(a);
    double fb = f(b);

    if (fa * fb > 0)
    {
        return;
    }

    double error = fabs(a - b), c = a;
    while (error > tol)
    {
        c = (a * fb - b * fa) / (fb - fa);
        double fc = f(c);

        cout << it << " \t" << a << " \t" << b << " \t" << c << " \t" << fc << " \t" << error << endl;

        if (fc == 0)
        {
            break;
        }
        else if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        it++;
        error = fabs(a - b) / c;
    }
    cout << "\n The approximate value of c is : " << c << "\n";
}
int main()
{
    vamus;
    double a, b, tolarence = 1e-6;
    cin >> a >> b;

    while (f(a) * f(b) >= 0)
    {
        cout << "Invalid range, please enter ahain interval: \n";
        cin >> a >> b;
    }

    falsi(a, b, tolarence);
    return 0;
}
