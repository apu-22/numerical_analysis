#include <bits/stdc++.h>
#define ll long long int
#define vamus                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
using namespace std;

void Quadratic_Interpolation(double x0, double y0, double x1, double y1, double x2, double y2, double x)
{
    double b0 = y0, b1 = (y1 - y0) / (x1 - x0), b2 = ((y2 - y1) / (x2 - x1) - b1) / (x2 - x0);
    double y = b0 + b1 * (x - x0) + b2 * (x - x0) * (x - x1);
    cout << "Interpolated value at x = " << x << " is y = " << y << endl;
}
int main()
{
    double x0, y0, x1, y1, x2, y2, x;

    cout << "Enter first point (x0 y0): ";
    cin >> x0 >> y0;

    cout << "Enter second point (x1 y1): ";
    cin >> x1 >> y1;

    cout << "Enter third point (x2 y2): ";
    cin >> x2 >> y2;

    cout << "Enter value of x to interpolate: ";
    cin >> x;

    Quadratic_Interpolation(x0, y0, x1, y1, x2, y2, x);
    return 0;
}