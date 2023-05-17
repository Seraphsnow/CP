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
    ll n;
    cin >> n;

    if(n == 1){
        ll num;
        cin >> num;
        cout << 1 << endl;
        return;
    }
    if(n == 2){
        ll n1, n2;
        cin >> n1 >> n2;
        if(n1 == n2){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
        return;
    }
    vector<ll> arr;
    ll num;
    cin >> num;
    arr.pb(num);
    for(int i = 1; i < n; i++){
        ll num;
        cin >> num;
        if(num!=arr.back())
            arr.pb(num);
    }
    //printVector<ll>(arr);
    ll ans = arr.size();
    if(ans == 1 || ans == 2){
        cout << ans << endl;
        return;
    }
    for(int i = 2; i < arr.size(); i++){
        if(((arr[i-2]-arr[i-1])*(arr[i-1]-arr[i]))>0){
            ans--;
        }
    }
    cout <<ans << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}