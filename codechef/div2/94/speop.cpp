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
    ll n, m;
    cin >> n >> m;
    ll **arr;
    arr = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ll[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    ll **col;
    col = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        col[i] = new ll[30];
        ll num = 1;
        for (int j = 0; j < 30; j++)
        {
            col[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                col[i][j] += ((arr[i][k] & num) ^ num);
            }
            num = num * 2;
        }
    }

    ll **row;
    row = new ll *[m];
    for (int i = 0; i < m; i++)
    {
        row[i] = new ll[30];
        ll num = 1;
        for (int j = 0; j < 30; j++)
        {
            row[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                row[i][j] += ((arr[k][i] & num) ^ num);
            }
            num = num * 2;
        }
    }

    ll total[30];
    for (int i = 0; i < 30; i++)
    {
        total[i] = 0;
        for (int j = 0; j < n; j++)
        {
            total[i] += col[j][i];
        }
    }

    ll **col2;
    col2 = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        col2[i] = new ll[30];
        ll num = 1;
        for (int j = 0; j < 30; j++)
        {
            col2[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                col2[i][j] += ((arr[i][k] & num) ^ 0);
            }
            num = num * 2;
        }
    }

    ll **row2;
    row2 = new ll *[m];
    for (int i = 0; i < m; i++)
    {
        row2[i] = new ll[30];
        ll num = 1;
        for (int j = 0; j < 30; j++)
        {
            row2[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                row2[i][j] += ((arr[k][i] & num) ^ 0);
            }
            num = num * 2;
        }
    }

    ll total2[30];
    for (int i = 0; i < 30; i++)
    {
        total2[i] = 0;
        for (int j = 0; j < n; j++)
        {
            total2[i] += col2[j][i];
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll num = arr[i][j];
            ll valnum = 0;
            ll pow = 1;
            for (int k = 0; k < 30; k++)
            {
                if (num & pow)
                {
                    valnum += total[k] - row[j][k] - col[i][k];
                }
                else
                {
                    valnum += total2[k] - row2[j][k] - col2[i][k];
                }
                pow = pow * 2;
            }
            ans = max<ll>(ans, valnum);
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