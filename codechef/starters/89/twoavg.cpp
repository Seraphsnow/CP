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
    ll n,m,k;
    cin >> n >> m >> k;
    ll suma= 0, sumb = 0;
    for(int i = 0; i< n; i++){
        ll num;
        cin >> num;
        suma+=num;
    }
    for(int i = 0; i< m; i++){
        ll num;
        cin >> num;
        sumb+=num;
    }
    if(k == 1){
        cout << -1 << endl;
        return;
    }
    ll ans = LONG_LONG_MAX;
    for(int i = 0; true; i++){
        if(sumb*n+i*n - suma*m-suma*i < 0){
            cout <<  min<ll>(ans,i) << endl;
            return;
        }
        if(k*m+k*i-sumb-i == 0) continue;
        ll kneeded = ((sumb*n+i*n - suma*m-suma*i)/(k*m+k*i-sumb-i)) + 1;
        
        ans = min<ll>(ans,i+kneeded);
    }
    
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}