#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

bool comp(ll a, ll b){
    return a < b;
}

void solve(){
    ll n;
    cin >> n;
    ll arr[n][3], num[2] = {0,0}, suminvar=0;
    for(int i = 0; i < n; i++){
        cin >> arr[i][2];
        arr[i][0] = num[0];
        arr[i][1] = num[1];
        num[arr[i][2]]++;
        if(!arr[i][2]){
            suminvar += arr[i][1];
        }
    }

    ll j = 0;
    while(j < n && arr[j][2]) j++;
    ll addThrough0 = 0;
    if(j < n) addThrough0 = num[0]-arr[j][1]-1;
    else addThrough0 = 0;

    j = n-1;
    while(j >=0 && !arr[j][2]) j--;
    ll addThrough1;
    if(j>=0) addThrough1 = arr[j][1] - num[0] + arr[j][0];
    else addThrough1 = 0;

    ll add=0;
    if(addThrough0 >= add && addThrough0 >= addThrough1) add = addThrough0;
    else if(addThrough1 >= add && addThrough1 >= addThrough0) add = addThrough1;
    cout << suminvar + add << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}