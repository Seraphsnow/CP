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

// Function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{

    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    // To store results of recursive call
    ll x1, y1;
    ll gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

ll modInverse(ll A, ll M, ll *inverse)
{
    if (inverse[A] != -1)
        return inverse[A];
    ll x, y;
    ll g = gcdExtended(A, M, &x, &y);
    if (g != 1)
    {
        cout << "Inverse doesn't exist";
        return -1;
    }

    else
    {

        // m is added to handle negative x
        ll res = (x % M + M) % M;
        inverse[A] = res;
        return res;
    }
}

ll calc(ll n, ll r, ll *inverse)
{
    if (n < r)
        return 0;
    ll ans = 1;
    for (int i = 1; i <= r; i++)
    {
        ans = (((ans * (n + 1 - i))%1000000007) * modInverse(i, 1000000007, inverse)) % 1000000007;
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[n];
    ll inverse[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        inverse[i] = -1;
    }
    inverse[n] = -1;
    sort(arr, arr + n);

    ll ans = 0;
    ll num = 0; // num = iCarr[i]-1
    if (arr[0] == 1)
    {
        ans = 1, num = 1;
    }

    for (int i = 1; i < n; i++)
    {
        if(arr[i] <= i+1)
            ans = (2 * ans + calc(i, min<ll>(arr[i] - 1, i + 1 - arr[i]), inverse)) % 1000000007;
        else{
            ans = (2*ans) % 1000000007;
        }
        // cout << num << endl;
        //cout << ans << endl;
    }
    cout << ans << endl;
    cout << endl;
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