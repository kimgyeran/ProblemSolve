#include <iostream>

using namespace std;

const int DIV = 1000;

class matrix
{
private:
    int mat[25] = {
        0,
    };
    int size;

public:
    matrix operator*(matrix b) const
    {
        matrix ret(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                for (int c = 0; c < size; c++)
                {
                    ret[j + i * size] = (ret[j + i * size] % DIV + (((mat[c + i * size] % DIV) * (b[j + c * size] % DIV)) % DIV) % DIV) % DIV;
                }
            }
        }
        return ret;
    }
    matrix operator%(int d)
    {
        matrix ret(size);
        for (size_t i = 0; i < size * size; i++)
        {
            ret[i] = mat[i] % d;
        }
        return ret;
    }
    int &operator[](int idx)
    {
        return mat[idx];
    }
    const int get(int idx)
    {
        return mat[idx];
    }
    matrix(int size)
    {
        this->size = size;
    }
    matrix(matrix &origin)
    {
        for (int i = 0; i < 25; i++)
        {
            mat[i] = origin[i];
        }

        size = origin.size;
    }
};

matrix mat_power(matrix a, long long b);

int main()
{
    long long n, b;
    cin >> n >> b;
    matrix mat(n);
    for (size_t i = 0; i < n * n; i++)
    {
        cin >> mat[i];
    }
    matrix ret = mat_power(mat, b);
    for (size_t i = 0; i < n * n; i++)
    {
        cout << ret[i] << ((i % n) == n - 1 ? '\n' : ' ');
    }

    return 0;
}

matrix mat_power(matrix a, long long b)
{
    if (b == 1)
        return a % DIV;
    if (b % 2 == 0)
    {
        matrix temp = (mat_power(a, b / 2) % DIV);
        temp = (temp * temp) % DIV;
        return temp;
    }
    else
    {
        matrix temp = (mat_power(a, b / 2) % DIV);
        temp = (((temp * temp) % DIV) * a)%DIV;
        return temp;
    }
}
