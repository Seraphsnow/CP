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

void solve()
{
    ll n;
    cin >> n;
    ll a[n];
    for(int i = 0; i <  n; i++){
        cin >> a[i];
    }
    ll b[n];
    for(int i = 0; i <  n; i++){
        cin >> b[i];
    }
    sort(a, a+n, greater<ll>());
    sort(b, b+n, greater<ll>());
    ll ia = 0, ib = 0;
    ll num = 0, ans = 1;
    for(int ib = 0; ib < n; ib++){
        while(ia<n){
            if(a[ia]>b[ib]){
                num++;
                ia++;
            }
            else{
                break;
            }
        }
        if(num>0){
            ans = (ans * num) % 1000000007;
            num--;
        }
        else{
            cout << 0 << endl;
            return;
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