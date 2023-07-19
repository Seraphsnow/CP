#include <bits/stdc++.h>
#include <limits.h>
// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>
#define ppll pair<pll, pll>
#define ull unsigned long long

template <typename T>
void printArr(T *arr, ll n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl
         << endl;
}

bool comp(pair<pll, ll> p1, pair<pll, ll> p2)
{
    return p1.fi.fi < p2.fi.fi || (p1.fi.fi == p2.fi.fi && p1.fi.se < p2.fi.se) || (p1.fi.fi == p2.fi.fi && p1.fi.se == p2.fi.se && p1.se < p2.se);
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    pair<pll, ll> arr[n];
    pll arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi.fi >> arr[i].fi.se >> arr[i].se;
    }

    sort(arr, arr + n, comp);
    for(int i = 0; i < n; i++){
        arr2[i] = {arr[i].fi.se, i};
    }
    sort(arr2, arr2+n);
    ll reward[n + 1];
    reward[n] = 0;
    ll next[n];
    ll currindex = 0, nextindex = 1;
    while (currindex < n)
    {
        if (nextindex == n)
        {
            next[arr2[currindex].se] = nextindex;
            currindex++;
        }
        else
        {
            while (nextindex < n)
            {
                if (arr2[currindex].fi >= arr[nextindex].fi.fi)
                {
                    nextindex++;
                }
                else
                {
                    break;
                }
            }
            next[arr2[currindex].se] = nextindex;
            currindex++;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        reward[i] = max<ll>(reward[i + 1], reward[next[i]] + arr[i].se);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << i <<" " <<arr[i].fi.fi << " " << arr[i].fi.se << "  " << arr[i].se << " " << next[i] << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << reward[i] << endl;
    // }
    cout << reward[0] << endl;
}