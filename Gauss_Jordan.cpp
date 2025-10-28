#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> cef;
vector<double> cons;

void gauss_jordan_PP(int n)
{
    for (int i = 0; i < n; i++)
    {
        // pivoting section
        int maxr = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(cef[k][i] > cef[maxr][i]))
                maxr = k;
        }

        swap(cef[i], cef[maxr]);
        swap(cons[i], cons[maxr]);

        // make diagola ==1
        double divisor = cef[i][i];
        for (int j = 0; j < n; j++)
        {
            cef[i][j] /= divisor;
        }
        cons[i] /= divisor;

        // make other rows zero in same column
        for (int k = 0; k < n; k++)
        {
            if (k == i)
                continue;
            double factor = cef[k][i];
            for (int j = 0; j < n; j++)
            {
                cef[k][j] -= factor * cef[i][j];
            }
            cons[k] -= factor * cons[i];
        }
    }
    cout << "Print the final value of those variables: \n";
    for (double val : cons)
    {
        cout << val << endl;
    }
}

int main()
{
    cout << "Enter the number of equation/variable: \n";
    int n;
    cin >> n;

    cef.resize(n, vector<double>(n));
    cons.resize(n);

    cout << "Enter the coefficeint of all equations: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Coefficeint for equation number: " << i + 1 << ": \n";
        for (int j = 0; j < n; j++)
        {
            cin >> cef[i][j];
        }
        cout << "Enter the constant for equation number : " << i + 1 << ": \n";
        cin >> cons[i];
    }

    gauss_jordan_PP(n);
    return 0;
}