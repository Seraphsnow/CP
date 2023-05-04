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
    sort(arr, arr+n);
    int num1;
    for(num1 = 0; num1<=n; num1++){
        if(arr[num1]!= 1){
            break;
        }
    }
    int i = num1;
    while(num1--){
        for(;i<n; i++){
            if(arr[i]%2 == 0){
                arr[i]++;
                break;
            }
        }
    }
    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans = (ans * arr[i]) % 998244353;
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