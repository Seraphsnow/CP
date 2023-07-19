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

    ll maxtime = 1000000000000000000;
    ll n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << "inf" << endl;
        return;
    }
    ll **arr;
    arr = new ll *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new ll[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = -1;
        }
    }
    // cout << n << " " << m << endl;
    for (int i = 0; i < m; i++)
    {
        ll u, v, y;
        cin >> u >> v >> y;
        // cout << "HI" << endl;
        // cout << u << " " << v << " " << y << endl;
        arr[u - 1][v - 1] = y;
        arr[v - 1][u - 1] = y;
        // cout << "HI" << endl;
    }
    ll ans = 0;
    vector<pair<string, ll>> strings;
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += "0";
    }
    s[0] = '1';
    ll count = 0;
    while (count < n * n)
    {
        // cout << s << endl;

        ll addtime = -1;
        vector<ll> newinds;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                for (int j = 0; j < n; j++)
                {
                    if (i != j && s[j] != '1' && arr[i][j] != -1)
                    {

                        if (addtime == -1)
                        {
                            addtime = arr[i][j];
                            newinds.pb(j);
                        }
                        else
                        {
                            if (addtime > arr[i][j])
                            {
                                addtime = arr[i][j];
                                newinds.clear();
                                newinds.pb(j);
                            }
                            else if (addtime == arr[i][j])
                            {
                                newinds.pb(j);
                            }
                        }
                    }
                }
            }
        }
        if (addtime == -1)
        {
            // cout << s << endl;
            cout << "inf" << endl;
            return;
        }
        if (addtime != 0)
        {
            ans += addtime;
            strings.pb({s, addtime});
        }
        bool done = false;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                for (int j = 0; j < n; j++)
                {
                    if (s[j] != '1' && arr[i][j] != -1)
                    {
                        arr[i][j] -= addtime;
                        arr[j][i] -= addtime;
                    }
                }
            }
        }
        for (int i = 0; i < newinds.size(); i++)
        {
            if (newinds[i] == n - 1)
            {
                done = true;
                break;
            }
            else
            {
                s[newinds[i]] = '1';
            }
        }
        if (done)
        {
            break;
        }
        count++;
    }
    cout << ans << " " << strings.size() << endl;
    for (int i = 0; i < strings.size(); i++)
    {
        cout << strings[i].fi << " " << strings[i].se << endl;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    while (t--)
    {
        solve();
    }
}