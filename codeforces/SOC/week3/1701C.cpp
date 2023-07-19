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

bool possible(ll* arr, ll n, ll time){
    ll left = 0;
    for(int i = 0; i < n; i++){
        if(arr[i]>time){
            left += arr[i] -time;
        }
        else{
            left = left - (time-arr[i])/2;
            if(left <= 0){
                return true;
            }
        }
    }
    if(left <= 0){
        return true;
    }
    else{
        return false;
    }
}

void solve()
{
    ll n,m;
    cin >> n >> m;
    ll arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < m; i++){
        ll num;
        cin >> num;
        arr[num-1]++;
    }
    sort(arr, arr+n, greater<ll>());
    ll max = arr[0], min = arr[n-1];
    while(true){
        if(max <= min){
            cout << max << endl;
            return;
        }
        ll mid = (max+min)/2;
        bool pos = possible(arr, n, mid);
        //cout<< pos << " " << n << " " << mid;
        if(pos){
            max = mid;
        }
        else{
            min = mid+1;
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