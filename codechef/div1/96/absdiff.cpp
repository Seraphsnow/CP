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

ll mypow(ll a, ll b, ll m)
{
    ll ans = 1, pow = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * pow) % m;
        }
        pow = (pow * pow) % m;
        b = b / 2;
    }
    return ans;
}

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        ll q = A / M;
        ll t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    pll vals[n];
    for (int i = 0; i < n; i++)
    {
        vals[i] = {LONG_LONG_MIN, LONG_LONG_MAX};
    }
    bool notposs = false;
    for (int i = 0; i < m; i++)
    {
        ll pos, val;

        cin >> pos >> val;
        if (notposs)
        {
            continue;
        }
        if (vals[pos - 1].fi == vals[pos - 1].se)
        {
            if (val != vals[pos - 1].fi)
            {
                notposs = true;
            }
        }
        else
        {
            vals[pos - 1] = {val, val};
        }
    }
    vector<ppll> conds;

    for (int i = 0; i < k; i++)
    {
        ll u, v, d;
        cin >> u >> v >> d;
        conds.pb({{min<ll>(u - 1, v - 1), max<ll>(u - 1, v - 1)}, {d, 0}});
    }
    if (notposs)
    {
        cout << "1NO" << endl;
        return;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            ll u = conds[j].fi.fi, v = conds[j].fi.se, d = conds[j].se.fi;
            ll umin, umax, vmin, vmax;
            if (vals[v].fi != LONG_LONG_MIN)
            {
                umin = max<ll>(vals[u].fi, vals[v].fi - d);
            }
            else
            {
                umin = vals[u].fi;
            }
            if (vals[v].se != LONG_LONG_MAX)
            {
                umax = min<ll>(vals[u].se, vals[v].se + d);
            }
            else
            {
                umax = vals[u].se;
            }

            if (vals[u].fi != LONG_LONG_MIN)
            {
                vmin = max<ll>(vals[v].fi, vals[u].fi - d);
            }
            else
            {
                vmin = vals[v].fi;
            }
            if (vals[u].se != LONG_LONG_MAX)
            {
                vmax = min<ll>(vals[v].se, vals[u].se + d);
            }
            else
            {
                vmax = vals[v].se;
            }
            vals[u] = {umin, umax};
            vals[v] = {vmin, vmax};
            if (vals[u].fi > vals[u].se)
            {
                cout << "NO" << endl;
                return;
            }
            if (vals[v].fi > vals[v].se)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
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