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
    string s;
    cin >> s;
    ll arr[26];
    for(int i = 0; i < 26; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++){
        arr[s[i]-97]++;
    }
    ll odd = 0, even = 0;
    for(int i = 0; i < 26; i++){
        if(arr[i]%2 == 1){
            odd++;
        }
        else if(arr[i]>0){
            even++;
        }
    }
    if(odd >= 2){
        cout << 0 << endl;
    }
    else if(odd == 1 && even > 0){
        cout << 1 << endl;
    }
    else if(odd == 1 && even == 0){
        cout << 2 << endl;
    }
    else if(odd == 0){
        cout << 1 << endl;
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