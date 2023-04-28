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
    return p1.fi.fi < p2.fi.fi || (p1.fi.fi == p2.fi.fi && p1.fi.se < p2.fi.se);
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    pair<pll, ll> arr[n];
    ll mymax = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi.fi >> arr[i].fi.se >> arr[i].se;
        mymax = max<ll>(mymax, arr[i].fi.se);
    }
    sort(arr, arr + n, comp);
    ll inters[n];
    ll index = 0;
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            if (index == n)
            {
                inters[i] = n;
                break;
            }
            else{
                if(arr[index].fi.se <= arr[i].fi.fi){
                    index++;
                }
                else{
                    inters[i] = index;
                    break;
                }
            }
        }
    }

    ll arr2[n];
    arr2[n-1] = arr[n-1].se;
    for (int i = n - 2; i >= 0; i++)
    {
        if(inters[i] == n){
            arr2[i] = max(arr[i].se, arr2[i+1]);
        }
        else{
            arr2[i] = max(arr[i].se+arr2[inters[i]], arr2[i+1]);
        }
    }
    cout << arr2[0] << endl;
}