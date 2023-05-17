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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll b[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    ll ans = 0;
    // printArr(a, n);
    // printArr(b, m);
    for (int i = 0; i < n; i++)
    {
        ll i1 = lower_bound(b, b + m, a[i]) - b;
        if (i1 == m)
        {
            ans = max<ll>(ans, a[i] - b[i1 - 1]);
        }
        else if (i1 == 0)
        {
            ans = max<ll>(ans, -a[i] + b[i1]);
        }
        else
        {
            ans = max<ll>(ans, min<ll>(a[i] - b[i1 - 1], -a[i] + b[i1]));
        }
        // cout << i << " " << i1 << " " << ans <<endl;
    }
    cout << ans << endl;
}