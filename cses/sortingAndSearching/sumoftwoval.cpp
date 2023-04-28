#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

bool comparator(pll p1, pll p2)
{
    return p1.fi < p2.fi;
}
int main(int argc, char *argv[])
{
    ll n, x;
    cin >> n >> x;
    pll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi;
        arr[i].se = i + 1;
    }
    sort(arr, arr + n, comparator);
    ll start = 0, end = n - 1;
    while (true)
    {
        if (start == end)
        {
            cout << "IMPOSSIBLE\n";
            break;
        }
        if (arr[start].fi + arr[end].fi == x)
        {
            cout << arr[start].se << " " << arr[end].se << endl;
            break;
        }
        else if (arr[start].fi + arr[end].fi < x)
        {
            start++;
        }
        else if (arr[start].fi + arr[end].fi > x)
        {
            end--;
        }
    }
}