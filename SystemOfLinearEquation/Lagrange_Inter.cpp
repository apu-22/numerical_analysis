// #include <bits/stdc++.h>
// using namespace std;

// void lag(double x0, double y0, double x1, double y1, double x2, double y2, double x)
// {
//     double l0 = ((x - x1) * (x - x2)) / ((x0 - x1) * (x0 - x2));
//     double l1 = ((x - x0) * (x - x2)) / ((x1 - x0) * (x1 - x2));
//     double l2 = ((x - x1) * (x - x0)) / ((x2 - x0) * (x2 - x1));

//     double y = l0 * y0 + l1 * y1 + l2 * y2;
//     cout << "Interpolated value at x = " << x << " is y = " <<   << endl;
// }
// int main()
// {
//     double x0, y0, x1, y1, x2, y2, x;
//     cout << "Enter the three data points:\n";
//     cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

//     cout << "Enter the valye of x to interpolated:\n";
//     cin >> x;

//     lag(x0, y0, x1, y1, x2, y2, x);
// }

#include <bits/stdc++.h>
using namespace std;

double lagrangeInterpolation(vector<double> &X, vector<double> &Y, double x)
{
    int n = X.size();
    double result = 0.0;

    for (int i = 0; i < n; i++)
    {
        double term = Y[i];  // start with y_i

        for (int j = 0; j < n; j++)
        {
            if (j != i)
                term *= (x - X[j]) / (X[i] - X[j]);
        }

        result += term;
    }

    return result;
}

int main()
{
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> X(n), Y(n);

    cout << "Enter data points (x y):\n";
    for (int i = 0; i < n; i++)
        cin >> X[i] >> Y[i];

    double x;
    cout << "Enter the value of x to interpolate: ";
    cin >> x;

    double y = lagrangeInterpolation(X, Y, x);
    cout << "\nInterpolated value at x = " << x << " is y = " << y << endl;

    return 0;
}
