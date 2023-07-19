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
    ll n, x;
    cin >> n >> x;
    pll pref[n + 1];
    pref[0] = {0, -1};
    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        pref[i + 1] = {pref[i].fi + num, i};
    }
    sort(pref, pref + n+1, comp);
    vector<mypref *> uniquePrefs;
    
    mypref *elem;
    elem = new mypref;
    elem->sum = pref[0].fi;
    elem->indices.pb(pref[0].se);
    uniquePrefs.pb(elem);
    for (int i = 1; i <= n; i++)
    {
        if (pref[i].fi == uniquePrefs.back()->sum)
        {
            uniquePrefs.back()->indices.pb(pref[i].se);
        }
        else
        {
            mypref *elem;
            elem = new mypref;
            elem->sum = pref[i].fi;
            elem->indices.pb(pref[i].se);
            uniquePrefs.pb(elem);
        }
    }
    // for(int i = 0; i < uniquePrefs.size();i++){
    //     cout << uniquePrefs[i]->sum << endl;
    //     for(int j = 0; j < uniquePrefs[i]->indices.size(); j++){
    //         cout << uniquePrefs[i]->indices[j] << " ";
    //     }
    //     cout << endl << endl;
    // }
    ll i1 = 0, i2 = 0;
    ll ans = 0;
    while (i1 < uniquePrefs.size() && i2 < uniquePrefs.size())
    {
        if(uniquePrefs[i1]->sum - uniquePrefs[i2]->sum > x){
            i2++;
        }
        else if(uniquePrefs[i1]->sum - uniquePrefs[i2]->sum < x){
            i1++;
        }
        else{
            ll i3 = uniquePrefs[i1]->indices.size()-1, i4 = uniquePrefs[i2]->indices.size()-1;
            while(i3 >= 0 && i4 >= 0){
                if(uniquePrefs[i1]->indices[i3] > uniquePrefs[i2]->indices[i4]){
                    ans+= i4+1;
                    i3--;
                }
                else{
                    i4--;
                }
            }
            i2++;
            i1++;
        }
    }
    cout << ans << endl;
}