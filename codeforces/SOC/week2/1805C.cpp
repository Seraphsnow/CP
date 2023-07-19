#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

template <typename T>
void printArr(T*arr, ll size){
    cout << endl << endl;
    for(ll i = 0; i < size; i++){
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl << endl;
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
T gcd(T a, T b){
    if(a%b == 0){
        return b;
    }
    else{
        return gcd(b, a%b);
    }
}

void adv_tokenizer(string s, char del)//Split string
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        cout << word << endl;
    }
}

void solve(){
    ll n,m;
    cin >> n >> m;
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    vector<ll> ks;
    ks.pb(arr[0]);
    for(int i = 0; i < n; i++){
        if(arr[i]!=ks.back()){
            ks.pb(arr[i]);
        }
    }
    for(int i = 0; i <m; i++){
        ld a,b,c;
        cin >> a >> b >> c;
        ld sq4ac = sqrt(4*a*c);
        ll index = upper_bound(ks.begin(), ks.end(), b-sq4ac) - ks.begin();
        if(index == ks.size()){
            cout << "NO\n";
        }
        else{
            ll num = ks[index];
            if(num < b+sq4ac){
                cout << "YES\n" << num << "\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}