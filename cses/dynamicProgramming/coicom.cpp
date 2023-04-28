#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

#define MOD 1000000007

int main(int argc, char *argv[])
{
    ll n, x;
    cin >> n >> x;
    ll coins[n];
    ll arr[x + 1];
    for(int i= 0; i < n; i++){
        cin >> coins[i];
    }
    for (int i = 0; i < x + 1; i++)
    {
        arr[i] = 0;
    }
    arr[0] = 1;
    for (int i = 1; i < x + 1; i++)
    {
        ll sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                sum += arr[i - coins[j]];
            }
        }
        arr[i] = sum % MOD;
    }
    cout << arr[x] << endl;
}