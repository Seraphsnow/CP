#include <bits/stdc++.h>
using namespace std;

// For policy data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

#define ordered_set tree<pll, null_type, less<pll>, rb_tree_tag, tree_order_statistics_node_update>

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
    ll n, q;
    cin >> n >> q;
    vector<ll> a;
    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        a.pb(num);
    }
    ordered_set s1, s2;
    ll start = 0;
    for (int i = 0; i < q; i++)
    {
        ll type;
        cin >> type;
        if (type == 2)
        {
            ll x;
            cin >> x;
            ll num = a[x - 1];
            ll i1 = s2.order_of_key({x, -1});

            ll i2 = s1.order_of_key({x, -1});
            ll times = i2 - i1;
            ll prev = num;
            ll done = false;
            for (int j = 0; j < times; j++)
            {
                ll newnum = 0;
                ll num = prev;
                while (num > 0)
                {
                    newnum = newnum + num % 10;
                    num /= 10;
                }
                if (prev == newnum)
                {
                    cout << prev << endl;
                    done = true;
                    break;
                }
                else
                {
                    prev = newnum;
                }
            }
            if (!done)
            {
                cout << prev << endl;
            }
        }
        else
        {
            ll l, r;
            cin >> l >> r;
            s1.insert({l - 1, start});
            s2.insert({r, start});
            start++;
        }
    }
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