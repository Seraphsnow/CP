#include <bits/stdc++.h>
#include <string>
#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    long long int ans = 1;
    long long int prev, count = 1;
    bool decreasing = 1;
    cin >> prev;
    for (int i = 1; i < n; i++)
    {
        int elem;
        cin >> elem;
        if (elem <= prev) // decreasing sequence
        {
            if (decreasing)
            {
                count++;
            }
            else
            {
                decreasing = 1;
                ans += count * (count + 1) / 2 - 1;
                count = 2;
            }
        }
        else
        {
            if (decreasing)
            {
                decreasing = 0;
                count++;
            }
            else
            {
                count++;
            }
        }
        prev = elem;
    }
    ans += count * (count + 1) / 2 - 1;
    cout << ans << endl;
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