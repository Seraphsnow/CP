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
    ll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    ll front[n];
    front[0] = arr[0];
    ll back[n];
    back[n-1] = arr[n-1];
    for(int i = 1; i < n; i++){
        front[i] = max(front[i-1], arr[i]);
    }
    for(int i = n-2; i >=0; i--){
        back[i] = max(back[i+1], arr[i]);
    }
    ll ans = 0;
    // printArr<ll>(front, n);
    // printArr<ll>(back, n);
    
    for(int i = 0; i < n; i++){
        ll height = min(front[i],back[i]);
        if(height >= arr[i]){
            ans+= height-arr[i];
        }
    }
    cout << ans << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}