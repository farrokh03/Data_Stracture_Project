#include <iostream>
using namespace std;

int sparse()
{
    int n;
    cin >> n;
    int size = 0;
    int sparse_matrix[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cin >> sparse_matrix[i][k];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (sparse_matrix[i][k] != 0)
            {
                size++;
            }
        }
    }

    int compact_matrix[size][3];
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (sparse_matrix[i][k] != 0)
            {
                compact_matrix[m][0] = i;
                compact_matrix[m][1] = k;
                compact_matrix[m][2] = sparse_matrix[i][k];
                m++;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << compact_matrix[i][0] << "\t";
        cout << compact_matrix[i][1] << "\t";
        cout << compact_matrix[i][2] << endl;
    }
}

int main()
{
    sparse();
    return 0;
}