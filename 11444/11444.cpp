#include <iostream>

using namespace std;

const int DIV = 1000000007;

struct mat2x2
{
    long long a;
    long long b;
    long long c;
    long long d;
};

mat2x2 mat_power(mat2x2 &a, long long b);
mat2x2 mat_mul(mat2x2 &a, mat2x2 &b);

int main()
{
    long long n = 0;
    cin >> n;
    mat2x2 mat = {1, 1, 1, 0};
    if (n <= 1)
        cout << n;
    else
        cout << mat_power(mat, n - 1).a;
    return 0;
}

mat2x2 mat_power(mat2x2 &a, long long b)
{
    if (b == 1)
        return a;
    if (b % 2 == 0)
    {
        mat2x2 temp = mat_power(a, b / 2);
        temp = mat_mul(temp, temp);
        return temp;
    }
    else
    {
        mat2x2 temp = mat_power(a, b / 2);
        temp = mat_mul(temp, temp);
        temp = mat_mul(temp, a);
        return temp;
    }
}

mat2x2 mat_mul(mat2x2 &a, mat2x2 &b)
{
    return {
        ((a.a * b.a) % DIV + (a.b * b.c) % DIV) % DIV, ((a.a * b.b) % DIV + (a.b * b.d) % DIV) % DIV,
        ((a.c * b.a) % DIV + (a.d * b.c) % DIV) % DIV, ((a.c * b.b) % DIV + (a.d * b.d) % DIV) % DIV};
}
