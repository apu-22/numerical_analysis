#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of point:\n";
    cin >> n;

    vector<double> x(n), y(n);

    cout << "Enter the data points:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    vector<vector<double>> table(n, vector<double>(n, 0.0));

    for (int i = 0; i < n; i++)
    {
        table[i][0] = y[i];
    }

    for (int j = 1; j < n; j++)
    {
        for (int i = 0; i < n - j; i++)
        {
            table[i][j] = (table[i + 1][j - 1] - table[i][j - 1]) / (x[i + j] - x[i]);
        }
    }

    cout << "Devided difference table:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << setw(12) << table[i][j] << " ";
        }
        cout << endl;
    }

    double dx;
    cout << "Enter value of x to interpolated:\n";
    cin >> dx;
    double yp = table[0][0];
    double factor = 1.0;

    for (int j = 1; j < n; j++)
    {
        factor *= (dx - x[j - 1]);
        yp += factor * table[0][j];
    }
    cout << "\nInterpolated value at x = " << dx << " is y = " << yp << endl;
    return 0;
}