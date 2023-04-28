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

bool comp1(ppll p1, ppll p2)
{
    return p1.fi.fi < p2.fi.fi || (p1.fi.fi == p2.fi.fi && p1.fi.se > p2.fi.se);
}
bool comp2(ppll p1, ppll p2)
{
    return p1.se.fi < p2.se.fi;
}

bool comp3(ppll p1, ppll p2)
{
    return p1.fi.fi > p2.fi.fi || (p1.fi.fi == p2.fi.fi && p1.fi.se < p2.fi.se);
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    ppll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi.fi >> arr[i].fi.se;
        arr[i].se.fi = i;
        arr[i].se.se = 0;
    }
    sort(arr,arr+n,comp3);
    ll minb = LONG_LONG_MAX;
    for(int i = 0; i < n; i++){
        if(minb <= arr[i].fi.se){
            arr[i].se.se = 1;
        }
        else{
            minb = arr[i].fi.se;
        }
    }
    sort(arr, arr+n, comp2);
    for(int i = 0; i < n; i++){
        cout << arr[i].se.se << " ";
        arr[i].se.se = 0;
    }

    cout << endl ;

    sort(arr, arr + n, comp1);
    ll maxb = LONG_LONG_MIN;
    for(int i = 0; i < n; i++){
        if(maxb >= arr[i].fi.se){
            arr[i].se.se = 1;
        }
        else{
            maxb = arr[i].fi.se;
        }
    }
    sort(arr, arr+n, comp2);
    for(int i = 0; i < n; i++){
        cout << arr[i].se.se << " ";
    }
}