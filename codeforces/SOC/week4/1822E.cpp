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
    if(n%2 ==1){
        cout << -1 << endl;
        return;
    }
    ll arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        arr[s[i] - 97]++;
    }
    for (int i = 0; i < 26; i++)
    {
        if(2*arr[i]>n){
            cout << -1 << endl;
            return;
        }
    }
    ll arr2[26];
    for(int i = 0; i < 26; i++){
        arr2[i] = 0;
    }
    for(int i = 0; i < n/2; i++){
        if(s[i] == s[n-1-i]){
            arr2[s[i]-97]++;
        }
    }
    sort(arr2, arr2+26, greater<ll>());
    ll max = arr2[0];
    ll sum = 0;
    
    for(int i = 1; i < 26; i++){
        sum+=arr2[i];
    }
    if(sum > max){
        cout << (sum+max+1)/2 << endl;
    }
    else{
        cout << max << endl;
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