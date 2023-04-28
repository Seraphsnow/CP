#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

int main(int argc, char *argv[])
{
    ll n, x;
    cin >> n >> x;
    ll coins[n];
    ll arr[x + 1];
    for (int i = 0; i < x + 1; i++)
    {
        arr[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        if (coins[i] <= x)
            arr[coins[i]] = 1;
    }
    for (int i = 1; i < x + 1; i++)
    {
        if (arr[i] == -1)
        {
            ll sum = INT_MAX;
            for (int j = 0; j < n; j++)
            {
                if (i - coins[j] > 0 && arr[i-coins[j]]!=-1)
                {
                    sum = min(sum, 1 + arr[i - coins[j]]);
                }
            }
            if (sum != INT_MAX)
                arr[i] = sum;
        }
    }
    cout << arr[x] << endl;
}