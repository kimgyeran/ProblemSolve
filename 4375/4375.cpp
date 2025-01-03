#include <iostream>
using namespace std;
int main()
{
    int n;

    while (true)
    {
        cin >> n;
        if (cin.eof())
            break;
        int r = 1 % n;
        int count = 1;
        while (r != 0)
        {
            r = (r * 10 + 1) % n;
            count++;
        }
        cout << count << '\n';
    }

    return 0;
}