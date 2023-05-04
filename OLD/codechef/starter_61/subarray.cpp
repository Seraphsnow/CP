#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    stack<int> mystack;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int elem;
        cin >> elem;
        if (mystack.empty() || mystack.top() == elem)
            mystack.push(elem);
        else
        {
            mystack.pop();
            count++;
        }
    }
    if(!mystack.empty() && mystack.top() == 1)count += mystack.size()/3;
    cout << count << endl;
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}