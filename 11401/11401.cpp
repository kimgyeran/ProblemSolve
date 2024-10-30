#include <iostream>

using namespace std;

long long int dnq_mod(int a, int k, int c);

long long fact(int n);

const int DIVISOR = 1000000007;

// 페르마의 소정리 : a가 정수 p 가 소수 a가 p로 나누어 떨어지지 않을 때 a^p 는 a mod p 와 나머지가 같고 양변에 a^-2를 곱하면 p 에대한 a의 모듈러 곱의 역원을 구할 수 있다.
//  a^(-1) mod p = a^(p-2) mod p
// 여기서 이항계수 공식의 n!/k!(n-k)! 의 나머지를 구하기 위해 k!(n-k)!의 모듈러 곱의 역원을 구하고 n!의 나머지를 구해 모듈러 곱의 분배법칙을 적용하면 된다
// 위의 공식에 대입하면 k!(n-k)!^(p-2)의 모듈러 연산을 위해 이전의 큰수의 제곱의 나머지를 구한 문제를 분할정복으로 해결한 방법을 사용한다.
//  팩토리얼을 구할때 결국 나누는 수보다 작은 수들의 곱이기 때문에 분배법칙을 적용해도 그 숫자 그대로 곱하는 것과 같다 따라서 팩토리얼의 작은수 부터 곱하며 각단계에 모듈러 연산을 해주면 된다
//  (a*b) mod c ㅌ (a mod c * b mod c) mod c 인데 여기서 a와 b 가 c보다 작고 c가 소수이기때문에 안의 연산은 없어도 됨

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    if (n - k < k)
        k = n - k;

    long long n_fact = fact(n);
    long long k_fact = fact(k);
    long long nmk_fact = fact(n - k);
    cout << (n_fact * dnq_mod((k_fact * nmk_fact) % DIVISOR, DIVISOR - 2, DIVISOR)) % DIVISOR;
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

long long fact(int n)
{
    long long temp = 1;
    for (size_t i = 1; i < n + 1; i++)
    {
        temp = (temp * i) % DIVISOR;
    }
    return temp;
}