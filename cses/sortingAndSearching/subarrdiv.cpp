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

bool comp(pll p1, pll p2)
{
    return p1.fi < p2.fi || (p1.fi == p2.fi && p1.se < p2.se);
}

class mypref
{
public:
    ll sum;
    vector<ll> indices;
    mypref()
    {
    }
};

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    pll pref[n];
    cin >> pref[0].fi;
    pref[0].fi =(pref[0].fi + 1000000000*n) % n;
    
    pref[0].se = 0;
    ll ans = 0;
    if (pref[0].fi == 0)
    {
        ans++;
    }
    for (int i = 1; i < n; i++)
    {
        ll num;
        cin >> num;
        pref[i].fi = (pref[i - 1].fi + num + 1000000000*n) % n;
        pref[i].se = i;
        
        if (pref[i].fi == 0)
        {
            ans++;
        }
    }
    sort(pref, pref + n);
    vector<mypref *> uni;
    mypref *elem;
    elem = new mypref;
    elem->sum = pref[0].fi;
    elem->indices.pb(pref[0].se);
    uni.pb(elem);
    for (int i = 1; i < n; i++)
    {
        if (pref[i].fi == uni.back()->sum)
        {
            uni.back()->indices.pb(pref[i].se);
        }
        else
        {
            mypref *elem;
            elem = new mypref;
            elem->sum = pref[i].fi;
            elem->indices.pb(pref[i].se);
            uni.pb(elem);
        }
    }
    for (int i = 0; i < uni.size(); i++)
    {
        ans += (uni[i]->indices.size() * (uni[i]->indices.size() - 1)) / 2;
    }
    cout << ans << endl;
}