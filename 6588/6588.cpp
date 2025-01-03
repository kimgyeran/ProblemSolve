#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<bool> arr(1000001, false);
    for (int i = 3; i < 1000; i += 2)
    {
        if (arr[i])
            continue;
        arr[i] = false;
        int temp;
        for (int j = 3; (temp = i * j) < 1000000; j += 2)
        {
            arr[temp] = true;
        }
    }
    int n;
    while (cin >> n)
    {
        if (n == 0)
            break;
        for (size_t i = 3; i <= (n / 2); i += 2)
        {
            if (!(arr[i] || arr[n - i]))
            {
                cout << n << " = " << i << " + " << n - i << '\n';
                break;
            }
        }
    }

    return 0;
}
