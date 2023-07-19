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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll a[n];
    ll **arr;
    arr = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        arr[i] = new ll[m];
    }
    if (m == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1)
    {
        if (a[0] == 0)
        {
            cout << m << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return 0;
    }
    if (a[0] == 0)
    {
        for (int i = 0; i < m; i++)
        {
            arr[0][i] = 1;
        }
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            arr[0][i] = 0;
        }
        arr[0][a[0] - 1] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] == 0)
        {
            arr[i][0] = (arr[i - 1][0] + arr[i - 1][1]) % 1000000007;
            for (int j = 1; j < m - 1; j++)
            {
                arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j] + arr[i-1][j + 1]) % 1000000007;
            }
            arr[i][m - 1] = (arr[i - 1][m - 1] + arr[i - 1][m - 2]) % 1000000007;
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                arr[i][j] = 0;
            }
            if (a[i] == 1)
            {
                arr[i][0] = (arr[i - 1][0] + arr[i - 1][1]) % 1000000007;
            }
            else if (a[i] == m)
            {
                arr[i][m - 1] = (arr[i - 1][m - 1] + arr[i - 1][m - 2]) % 1000000007;
            }
            else{
                ll j = a[i]-1;
                arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j] + arr[i-1][j + 1]) % 1000000007;
            }
        }
    }
    ll ans = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0;i<m; i++){
        ans= (ans + arr[n-1][i])%1000000007;
    }
    cout << ans << endl;
}