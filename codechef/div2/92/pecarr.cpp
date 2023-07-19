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

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(a, a + n);
    vector<pll> uni;
    uni.pb({a[0], 1});
    for (int i = 1; i < n; i++)
    {
        if (uni.back().fi == a[i])
        {
            uni.back().se++;
        }
        else
        {
            uni.pb({a[i], 1});
        }
    }
    ll maxredposs;
    if (uni.size() >= 2)
    {
        maxredposs = 3 * uni.size() - 2;
        if (maxredposs < n)
        {
            cout << (n - maxredposs) * k << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else
    {
        if (a[0] == 1)
        {
            if (n == 2)
            {
                cout << 1 * k << endl;
            }
            else
            {
                cout << (n - 2) * k << endl;
            }
        }
        else
        {
            if (n == 2)
            {
                cout << 1 * k << endl;
            }
            else if (n == 3)
            {
                cout << 1 * k << endl;
            }
            else if (n == 4)
            {
                cout << 2 * k << endl;
            }
            else
            {
                cout << (n - 3) * k << endl;
            }
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