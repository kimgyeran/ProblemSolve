#include <iostream>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m;
    int nm[n * m];
    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < m; x++)
        {
            cin >> nm[x + m * y];
        }
    }
    cin >> m >> k;
    int mk[m * k];
    for (size_t y = 0; y < m; y++)
    {
        for (size_t x = 0; x < k; x++)
        {
            cin >> mk[x + k * y];
        }
    }
    int result[n * k];
    int sum = 0;
    for (size_t i = 0; i < n; i++)
    {
        /* code */

        for (size_t j = 0; j < k; j++)
        {
            /* code */

            for (size_t c = 0; c < m; c++)
            {
                sum += nm[c + m * i] * mk[j + k * c];
            }
            result[j + i * k] = sum;
            sum = 0;
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            cout << result[j + i * k] << ' ';
        }
        cout << "\n";
    }

    return 0;
}