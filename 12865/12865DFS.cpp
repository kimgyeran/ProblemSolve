#include <iostream>
#include <vector>
#include <map>

using namespace std;

class item
{
public:
    int Value;
    int Weight;
    item(int w , int v)
    {
        Value = v;
        Weight = w;
    }
    item();
};

class bag
{
public:
    bool hasValue;
    int Size;
    int Value;
    bag(int size)
    {
        Size = size;
    }
    bag()
    {
        hasValue = false;
    };
};
int P(int n, int k);
bag **bag_map;
vector<item> items;
int main()
{
    int n, k;
    cin >> n >> k;
    bag_map = new bag *[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        bag_map[i] = new bag[k + 1];
    }
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        items.push_back(item(a, b));
    }
    cout << P(n, k);
    return 0;
}

int P(int n, int k)
{
    if (bag_map[n][k].hasValue)
        return bag_map[n][k].Value;

    if (n == 0 || k == 0)
        return 0;
    int case1 = P(n - 1, k);
    int r = k - items[n - 1].Weight;
    int case2 = r >= 0 ? P(n - 1, r) + items[n - 1].Value : -1;
    if (case1 >= case2)
    {
        bag_map[n][k].Value = case1;
        bag_map[n][k].Size = k;
        bag_map[n][k].hasValue = true;
        return case1;
    }
    else
    {
        bag_map[n][k].Value = case2;
        bag_map[n][k].Size = k;
        bag_map[n][k].hasValue = true;
        return case2;
    }
}