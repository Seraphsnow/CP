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
    ll n;
    cin >> n;
    ll arr[max<ll>(n+1,10)];
    arr[0] = 0;
    for(int i = 1; i < 10; i++){
        arr[i] = 1;
    }
    for (int i = 10; i <= n; i++)
    {
        ll num = i;
        bool arr2[10];
        for (int j = 0; j < 10; j++)
        {
            arr2[j] = false;
        }
        while (num > 0)
        {
            arr2[num % 10] = true;
            num = num / 10;
        }
        ll ans = 1000000;
        for (int j = 1; j < 10; j++)
        {
            if (arr2[j])
            {
                //cout << arr[i-j] << endl << i-j << endl;
                ans = min<ll>(ans, 1 + arr[i-j]);
                //cout << ans << endl;
            }
        }
        arr[i] = ans;
        // cout << arr[i] << " " << i << endl;
        // break;
    }
    cout << arr[n] << endl;
}