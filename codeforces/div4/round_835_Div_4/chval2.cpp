#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

void solve()
{
    ll n;
    cin >> n;
    ll count = 0;
    ll arr[n];
    ll l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i == l)
            continue;
        else
        {
            if (arr[i] == arr[l])
            {
                r = i;
                continue;
            }
            else
            {
                if ((l == 0 || arr[l - 1] > arr[l]) && (r == n - 1 || arr[r] < arr[r + 1]))
                {
                    count++;
                }
                l = i;
                r = i;
            }
        }
    }
    if ((l == 0 || arr[l - 1] > arr[l]) && (r == n - 1 || arr[r] < arr[r - 1]))
    {
        count++;
    }
    if(count != 1) cout << "NO\n";
    else cout << "YES\n";
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