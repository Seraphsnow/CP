#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

template <typename T>
void printArr(T *arr, ll size)
{
    cout << endl
         << endl;
    for (ll i = 0; i < size; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
}

template <typename T>
void printVector(vector<T> arr)
{
    cout << endl
         << endl;
    for (ll i = 0; i < arr.size(); i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
}

template <typename T>
T gcd(T a, T b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void adv_tokenizer(string s, char del) // Split string
{
    stringstream ss(s);
    string word;
    while (!ss.eof())
    {
        getline(ss, word, del);
        cout << word << endl;
    }
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a;

    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        a.pb(num);
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    ll prev = a[0];
    vector<pll> un;
    vector<ll> elems;
    un.pb({prev, 1});
    elems.pb(prev);
    for (int i = 1; i < n; i++)
    {
        if (a[i] == prev)
        {
            un.back().se++;
        }
        else
        {
            prev = a[i];
            un.pb({prev, 1});
            elems.pb(prev);
        }
    }
    ll max = un.back().fi;
    for (int i = 0; i < un.size(); i++)
    {
        ans += ((un[i].se) * (un[i].se - 1) * (un[i].se - 2));
        ll k = 2;
        ll elem = un[i].fi;
        if (un[i].fi * 4 > max)
        {
            continue;
        }
        while (true)
        {
            if (elem * k * k > max)
            {
                break;
            }
            auto it = lower_bound(elems.begin() + i + 1, elems.end(), elem * k * k);
            if (it != elems.end() && *it == elem * k * k)
            {
                auto it2 = lower_bound(elems.begin() + i + 1, elems.end(), elem * k);
                if (*it2 == elem * k)
                {
                    ans += un[i].se * un[it - elems.begin()].se * un[it2 - elems.begin()].se;
                }
            }
            k++;
        }
    }
    cout << ans << endl;
}


int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}