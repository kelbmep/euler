#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b;
    cin >> n;
    set<int> *arr = new set<int> [n + 1];
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a;
        cin >> b;
        arr[a].insert(b);
        arr[b].insert(a);
    }
    int curr = 1;
    stack <int> prev;
    prev.push(1);
    cout << 1 << " ";
    for(int i = 1; i < 2 * n - 1; i++)
        for(set<int>::iterator it = arr[curr].begin(); it != arr[curr].end(); it++)
        {
            if(*it != prev.top())
            {
                prev.push(curr);
                cout << *it << " ";
                curr = *it;
                break;
            }
            if(arr[curr].size() == 1 && i != 1)
            {
                arr[prev.top()].erase(curr);
                cout << *it << " ";
                curr = *it;
                prev.pop();
                break;
            }
        }
    return 0;
}
