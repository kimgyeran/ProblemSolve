#include <iostream>

using namespace std;
long long int dnq_mod(int a, int k, int c);
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << dnq_mod(a, b, c);
    return 0;
}

long long int dnq_mod(int a, int k, int c)
{
    if (k == 1)
        return a % c;
    long long int temp = 0;
    if (k % 2 == 0)
    {
        temp = (dnq_mod(a, k / 2, c) * dnq_mod(a, k / 2, c)) % c;
    }
    else
    {
        temp = (dnq_mod(a, k / 2, c) * dnq_mod(a, k / 2 + 1, c)) % c;
    }
    return temp;
}