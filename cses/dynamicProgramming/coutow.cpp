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
#define MOD 1000000007
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
    ll t;
    cin >> t;
    ll arr[t];
    ll mymax = 0;
    for(int i = 0; i < t; i++){
        cin >> arr[i];
        mymax = max<ll>(mymax, arr[i]);
    }
    ll f[max<ll>(3,mymax+1)], g[max<ll>(3,mymax+1)];
    f[1] = 2;
    f[2] = 8;
    // g[1] = 0;
    // g[2] = 0;
    ll pow = 4;
    for(int i = 3; i <=mymax; i++){
        // g[i] = (3*g[i-1] + pow -2 ) % MOD;
        f[i] = (6*f[i-1] -7*f[i-2]) % MOD;
        while(f[i]<0){
            f[i]+=MOD;
        }
        //pow = (pow * 2)% MOD;
    }
    // for(int i = 1; i <= 10; i++){
    //     cout << i << endl;
    //     cout << f[i] << endl;
    //     //cout << g[i] << endl;

    // }
    for(int i = 0; i < t;i++){
        cout << f[arr[i]] << endl;
    }
}