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

string s;
ll *a;
ll ***mem;
pll add(pll p1, pll p2)
{
    ll inv = modInverse(gcd(p1.se, p2.se), 1000000007);
    return {(((p1.fi * p2.se + p2.fi * p1.se) % 1000000007) * inv) % 1000000007, (((p1.se * p2.se) % 1000000007) * inv) % 1000000007};
}

ll val(ll ind1, ll ind2, ll done, ll k)
{
    if (mem[ind1][ind2][done] != -1)
    {
        return mem[ind1][ind2][done];
    }
    if (s[done] == 'L')
    {
        ll val1 = val(ind1, ind2 - 1, done + 1, k);
        ll val2 = val(ind1, ind2 - 1, done, k);
        val2 = (val2 * (ind2 - ind1 - 1)) % 1000000007;
        ll ans = val1 + val2;
        ans = (ans * modInverse(ind2 - ind1, 1000000007)) % 1000000007;
        mem[ind1][ind2][done] = ans;
        return ans;
    }
    else
    {
        ll val1 = val(ind1 + 1, ind2, done + 1, k);
        ll val2 = val(ind1 + 1, ind2, done, k);
        val2 = (val2 * (ind2 - ind1 - 1)) % 1000000007;
        ll ans = val1 + val2;
        ans = (ans * modInverse(ind2 - ind1, 1000000007)) % 1000000007;
        mem[ind1][ind2][done] = ans;
        return ans;
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    mem = new ll **[n];
    for (int i = 0; i < n; i++)
    {
        mem[i] = new ll *[n];
        for (int j = 0; j < n; j++)
        {
            mem[i][j] = new ll[k + 1];
            for (int l = 0; l <= k; l++)
            {
                mem[i][j][l] = -1;
            }
        }
    }
    a = new ll[n];
    ll *prefs;
    prefs = new ll[n + 1];
    prefs[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefs[i + 1] = (prefs[i] + a[i]) % 1000000007;
    }
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            mem[i][j][k] = ((prefs[j + 1] - prefs[i]) % 1000000007 + 1000000007);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            mem[i][i][j] = a[i];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int l = k - 1; l >= 0; l--)
    //         {
    //             if (s[l] == 'L')
    //             {
    //                 mem[i][j][l] = ((mem[i][j - 1][l + 1] + (mem[i][j - 1][l] * (j - i)) % 1000000007) % 1000000007) * (modInverse(j + 1 - i, 1000000007)) % 1000000007;
    //             }
    //             else
    //             {
    //                 mem[i][j][l] = ((mem[i+1][j][l + 1] + (mem[i+1][j][l] * (j - i)) % 1000000007) % 1000000007) * (modInverse(j + 1 - i, 1000000007)) % 1000000007;
    //             }
    //         }
    //     }
    // }

    ll ans = val(0, n - 1, 0, k);
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