#include <bits/stdc++.h>
using namespace std;

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

vector<ll> decToBinary(ll n)
{
    // Size of an integer is assumed to be 32 bits
    vector<ll> ans;
    for(int i = 0; i < 30; i++){
        ans.pb(n & 1);
        n = n/2;
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    ll arr[n], ors = 0;
    vector<ll> bins[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        ors = ors | arr[i];
        bins[i] = decToBinary(arr[i]);
    }
    if (ors == 0)
    {
        cout << n << endl;
        return;
    }
    ll left = -1, right = n, onholdleft = 0, onholdright = 0;
    vector<ll> ones[30];
    for (int i = 0; i < 30; i++)
    {
        for(ll j = 0; j < n; j++){
            if(bins[j][i] == 1){
                ones[i].pb(j);
            }
        }
    }
    for(int i = 0; i < 30; i++){
        if(ones[i].size() == 1){
            cout << -1 << endl;
            return;
        }
    }
    ll left = -1, right = n;
    for(int i = 0; i < 30; i++){
        ll num1 = ones[i].size();
        if(num1 == 0 || ones[i][0]<left || ones[i][num1-1] > right){
            continue;
        }
        
    }
}

int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}