#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n;
    queue<int> q;
    vector<int> s;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        if (v[i] == 0)
            s.push_back(temp);
    }
    for(auto it = s.rbegin();it!=s.rend();it++){
        q.push(*it);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        std::cin >> temp;
        q.push(temp);
        cout<<q.front()<<' ';
        q.pop();
        
    }
}