#include <bits/stdc++.h>
#define ll long long int
#define vamus                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;
using namespace std;

void Linear_Interpolating(double x0, double y0, double x1, double y1, double x)
{
    double y = y0 + ((y1 - y0) / (x1 - x0)) * (x - x0);

    cout << "Interpolated value at x = " << x << " is y = " << y << endl;
}
int main()
{
    double x0, y0, x1, y1, x;
    cout << "Enter the first point: " << endl;
    cin >> x0 >> y0;

    cout << "Enter the second point: " << endl;
    cin >> x1 >> y1;

    if (x0 == x1)
    {
        cout << "Invalide, please inter the different value of x0 & x1." << endl;
    }

    cout << "Enter the value of x to interpolate: " << endl;
    cin >> x;

    Linear_Interpolating(x0, y0, x1, y1, x);
    return 0;
}