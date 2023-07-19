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
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    ll main;
    if(arr[0] == n){
        main = n-1;
    }
    else{
        main = n;
    }
    ll mainind;
    for(int i = 0; i < n; i++){
        if(arr[i] == main){
            mainind = i;
            break;
        }
    }
    ll r;
    if(mainind == n-1){
        r = n-1;
    }
    else{
        r = mainind-1;
    }
    ll l=0;
    for(int i = r-1; i >=0; i--){
        if(arr[i] < arr[0]){
            l = i+1;
            break;
        }
    }
    for(int i= r+1; i < n; i++){
        cout << arr[i] << " ";
    }
    for(int i = r; i >=l; i--){
        cout << arr[i] << " ";
    }
    for(int i = 0; i < l; i++){
        cout << arr[i] << " ";
    }
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