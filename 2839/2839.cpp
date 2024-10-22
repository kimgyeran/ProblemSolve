#include <iostream>

int arr[5001] = {
    0,
    -1,
    -1,
    1,
    -1,
    1,
    -2,
};
int B(int n);

int main()
{
    int n;
    std::fill_n(arr+6,4995,-2);
    std::cin >> n;
    std::cout << B(n);
    return 0;
}

int B(int n)
{
    if (arr[n] == -2)
    {
        int a = B(n - 3);
        int b = B(n - 5);
        if (a == b)
        {
            if (a == -1)
                return -1;
            arr[n] = a + 1;
            return arr[n];
        }
        if (a > b)
        {
            if (b == -1)
            {
                return (arr[n] = a + 1);
            }
            else
            {
                return (arr[n] = b + 1);
            }
        }
        else
        {
            if (a == -1)
            {
                return (arr[n] = b + 1);
            }
            else
            {
                return (arr[n] = a + 1);
            }
        }
    }
    return arr[n];
}