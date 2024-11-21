#include <iostream>
#include <vector>

using namespace std;

long long GetCutLength(long long h, vector<long long> &arr);
long long binarysearch(long long prev, long long want, long l, long r, vector<long long> &arr);
int main()
{
    long long N, Want;
    vector<long long> arr;
    long long max = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> Want;

    for (size_t i = 0; i < N; i++)
    {
        long long temp;
        cin >> temp;
        max = temp > max ? temp : max;
        arr.push_back(temp);
    }
    cout << binarysearch(1000000000, Want, 0, max, arr);

    return 0;
}

long long GetCutLength(long long h, vector<long long> &arr)
{
    long long sum = 0;
    for (long long r : arr)
    {
        sum += (r - h) > 0 ? r - h : 0;
    }
    return sum;
}

long long binarysearch(long long prev, long long want, long l, long r, vector<long long> &arr)
{

    long long m = (l + r) / 2;
    long long cut_sum = GetCutLength(m, arr);
    if (m == l)
    {
        if (cut_sum < want)
            return prev;
        return m;
    }
    if (cut_sum > want)
    {
        return binarysearch(m, want, m, r, arr);
    }
    else if (cut_sum == want)
    {
        return m;
    }
    else
    {
        return binarysearch(prev, want, l, m, arr);
    }
}