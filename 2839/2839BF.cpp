#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int count = 0;
    while (n > 0 && n % 5 != 0)
    {
        n -= 3;
        count++;
    }
    if (n % 5 == 0)
        count += n / 5;
    else if (n < 0)
        count = -1;
    std::cout<<count;
    return 0;
}
