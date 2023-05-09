#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

bool comp(pair<pll,ll> p1, pair<pll,ll> p2)
{
    return p1.fi.fi < p2.fi.fi;
}
int main(int argc, char *argv[])
{
    ll n, m;
    cin >> n >> m;
    ll arr3[n], arr2[n];
    pair<pll, ll> arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi.fi;
        arr2[i] = arr[i].fi.fi;
        arr[i].fi.se = i;
    }
    sort(arr, arr + n, comp);
    ll rounds = 1, prev = arr[0].fi.se;
    arr[0].se = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i].fi.se > prev)
        {
            prev = arr[i].fi.se;
        }
        else
        {
            prev = arr[i].fi.se;
            rounds++;
        }
        arr[i].se = rounds;
    }

    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        if (a > b)
        {
            ll temp = a;
            a = b;
            b = temp;
        }
// b is greater than a
        if(a == b){
            cout << rounds << endl;
            continue;
        }
        a--;
        b--;
        ll num1 = arr2[a], num2 = arr2[b];
        arr2[b] = num1;
        arr2[a] = num2;



        arr[num1-1].fi.se = b;
        
        arr[num2-1].fi.se = a;

    }
}