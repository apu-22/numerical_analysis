
#include <bits/stdc++.h>
#define ll long long int
#define vamus                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
using namespace std;

void gaussianElimination(vector<vector<double>> &a, vector<double> &b)
{
    int n = a.size();

    // Forward elimination (no pivoting)
    for (int i = 0; i < n; i++)
    {
        for (int k = i + 1; k < n; k++)
        {
            double factor = a[k][i] / a[i][i];
            for (int j = i; j < n; j++)
            {
                a[k][j] -= factor * a[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    // Back substitution
    vector<double> result(n);
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] = b[i];
        for (int j = i + 1; j < n; j++)
        {
            result[i] -= a[i][j] * result[j];
        }
        result[i] /= a[i][i];
    }

    // Output solution
    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << " = " << result[i] << endl;
    }
}

int main()
{
    // vamus;

    cout << "Enter the number of variables:\n";
    int n;
    cin >> n;

    vector<vector<double>> cef(n, vector<double>(n));
    vector<double> con(n);

    cout << "Enter coefficients of the equations:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "For equation no --> " << i + 1 << ":\n";
        for (int j = 0; j < n; j++)
        {
            cin >> cef[i][j];
        }
        cout << "Enter the constant for equation no --> " << i + 1 << ":\n";
        cin >> con[i];
    }

    gaussianElimination(cef, con);
    return 0;
}
