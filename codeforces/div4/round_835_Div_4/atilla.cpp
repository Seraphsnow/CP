#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

void solve(){
    ll n;
    cin >> n;
    bool arr[26];
    for(int i = 0; i < 26; i++){
        arr[i] = 0;
    }

    for(int i = 0; i < n; i++){
        char letter;
        cin >> letter;
        arr[letter-97] = 1;
    }
    ll ans=0;
    for(int i = 0; i < 26; i++){
        if(arr[i]) ans = i+1;
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