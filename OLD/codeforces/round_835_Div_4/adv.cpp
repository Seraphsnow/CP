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
    ll arr[n];
    cin >> arr[0] >> arr[1];
    ll max1 = max(arr[0],arr[1]), max2 = min(arr[0],arr[1]);
    for(ll i = 2; i < n; i++){
        cin >> arr[i];
        if(arr[i]>max1){
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i]>max2){
            max2 = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] == max1) cout << max1-max2 << " ";
        else cout << arr[i]-max1 << " ";
    }
    cout << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}