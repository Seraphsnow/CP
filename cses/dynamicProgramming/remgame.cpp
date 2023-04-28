#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

ll opt(ll i, ll j, ll **arr, ll *num, ll n)
{
    if (i >= n || j >= n || i <= 0 || j <= 0)
    {
        return 0;
    }
    if (arr[i][j] != -1)
    {
        return arr[i][j];
    }
    if (i == j)
    {
        arr[i][j] = num[i];
        return arr[i][j];
    }
    else if (i > j)
    {
        arr[i][j] = 0;
        return 0;
    }
    else
    {
        ll ans = opt(i + 2, j, arr, num, n) + num[i];
        ans = max(ans, opt(i + 1, j - 1, arr, num, n) + num[i]);
        ans = max(ans, opt(i + 1, j - 1, arr, num, n) + num[j]);
        ans = max(ans, opt(i, j - 2, arr, num, n) + num[j]);
    }
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    ll num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    ll **arr;
    arr = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ll[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = -1;
        }
    }
    cout << opt(0, n - 1, arr, num, n) << endl;
}