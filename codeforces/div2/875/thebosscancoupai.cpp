#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// #define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

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

template <typename T>
T min3(T a, T b, T c)
{
    return min<T>(a, min<T>(b, c));
}

template <typename T>
T min4(T a, T b, T c, T d)
{
    return min<T>(min<T>(a, d), min<T>(b, c));
}

template <typename T>
T max3(T a, T b, T c)
{
    return max<T>(a, max<T>(b, c));
}

template <typename T>
T max4(T a, T b, T c, T d)
{
    return max<T>(max<T>(a, d), max<T>(b, c));
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

bool comp(pll p1, pll p2)
{
    return p1.fi < p2.fi;
}

void solve()
{
    ll n;
    cin >> n;
    pll a[n];
    vector<ll> bs[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].se;
        bs[a[i].fi].pb(a[i].se);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(bs[i].begin(), bs[i].end());
    }
    vector<pll> bsnew[n + 1];

    for (int i = 1; i <= n; i++)
    {
        if (bs[i].size() > 0)
        {
            bsnew[i].pb({bs[i][0], 1});
            for (int j = 1; j < bs[i].size(); j++)
            {
                if (bs[i][j] == bsnew[i].back().fi)
                {
                    bsnew[i].back().se++;
                }
                else
                {
                    bsnew[i].pb({bs[i][j], 1});
                }
            }
        }
    }
    ll ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i * i > 2 * n)
        {
            break;
        }
        if (bsnew[i].size() == 0)
        {
            // cout << i << endl;
            continue;
        }
        ll i1 = 0, i2 = bsnew[i].size() - 1;
        while (i1 <= i2)
        {
            if ((bsnew[i][i1].fi + bsnew[i][i2].fi) == (i * i))
            {
                if (i1 == i2)
                {
                    ans += (bsnew[i][i1].se * (bsnew[i][i2].se - 1))/2;
                    i1++;
                    i2--;
                }
                else
                {
                    ans += bsnew[i][i1].se * bsnew[i][i2].se;
                    i1++;
                    i2--;
                }
            }
            else if ((bsnew[i][i1].fi + bsnew[i][i2].fi) > (i * i))
            {
                i2--;
            }
            else
            {
                i1++;
            }
        }
        for (int j = i + 1; j <= n; j++)
        {
            // cout << "hi" << endl;
            if (i * j > 2 * n)
            {
                break;
            }
            ll i1 = 0, i2 = bsnew[j].size() - 1;
            while ((i1 <= (bsnew[i].size() - 1)) && (i2 >= 0))
            {
                if ((bsnew[i][i1].fi + bsnew[j][i2].fi) == (i * j))
                {
                    ans += bsnew[i][i1].se * bsnew[j][i2].se;
                    i1++;
                    i2--;
                }
                else if ((bsnew[i][i1].fi + bsnew[j][i2].fi) > (i * j))
                {
                    i2--;
                }
                else
                {
                    i1++;
                }
            }
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