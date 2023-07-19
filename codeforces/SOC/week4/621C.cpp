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

long double prob(ll l, ll r, ll p){
    ll numprime = r/p - (l-1)/p;
    ll total = r-l+1;
    return (1.0*numprime)/total;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,p;
    cin >> n >> p;
    pair<ll,ll> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].fi >> arr[i].se;
    }
    long double ans = 0;
    for(int i = 0; i < n; i++){

        ans = ans + 2*prob(arr[i].fi, arr[i].se, p) + 1*(1-prob(arr[i].fi, arr[i].se, p))*(prob(arr[(n+i-1)%n].fi, arr[(n+i-1)%n].se, p)+ prob(arr[(i+1)%n].fi, arr[(i+1)%n].se, p));

    }
    cout<< setprecision(10  ) << 1000*ans << endl;
}