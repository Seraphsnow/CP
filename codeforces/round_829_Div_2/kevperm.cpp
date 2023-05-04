#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int start = (n + 1 )/ 2;
    for (int i = 0; i < n / 2; i++)
    {
        cout << start - i << " " << n - i << " ";
    }
    if (n % 2)
    { // odd
        cout << 1 << " " << endl;
    }
    else{
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}