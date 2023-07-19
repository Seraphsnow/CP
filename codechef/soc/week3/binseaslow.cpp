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

ll g(ll k, pll ** arr, ll n)
{
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(arr[i][j].fi-arr[i][j].se <= k){
                ans++;
            }
        }
    }
    return ans;
}

void solve()
{
    ll n, u;
    cin >> n >> u;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll b[n];
    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }
    if(u > (n)*(n+1)/2){
        cout << -1 << endl;
        return;
    }
    pll** arr;
    arr = new pll* [n];
    for(int i = 0; i < n; i++){
        arr[i] = new pll [n];
        for(int j = i; j < n; j++){
            arr[i][j] = {LONG_LONG_MIN, LONG_LONG_MAX};
            for(int k = i; k <=j; k++){
                if(a[k] > arr[i][j].fi){
                    arr[i][j].fi = a[k];
                }
                if(b[k]<arr[i][j].se){
                    arr[i][j].se = b[k];
                }
            }
        }
    }
    ll max = 1;
    while (true)
    {
        // cout << max << endl;
        ll gk = g(max, arr, n);
        cout << gk << " " << max << " " << endl
              << endl;
        if (gk < u)
        {
            max = max * 2;
        }
        else
        {
            break;
        }
    }
    ll min = max / 2;
    while (true)
    {
        if (min == max)
        {
            //cout << min << endl;
            ll gk = g(min, arr, n);
            cout << gk << " " << min << " " << endl
                 << endl;
            if (gk == u)
                cout << min << endl;
            else
                cout << -1 << endl;
            return;
        }
        else if (min > max)
        {
            cout << -1 << endl;
            return;
        }
        ll mid = (min + max) / 2;
        //cout << mid << endl;
        ll gk = g(mid, arr, n);
        cout << gk << " " << mid << " " << endl
             << endl;
        if (gk > u)
        {
            max = mid - 1;
        }
        else if (gk == u)
        {
            max = mid;
        }
        else
        {
            min = mid + 1;
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