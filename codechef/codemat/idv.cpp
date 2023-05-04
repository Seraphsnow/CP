#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll x, ll y){
    if(x%y == 0) return y;
    else return gcd(y, x%y);
}

void solve(){
    ll N,x,y;
    cin >> N >> x >> y;
    ll lcm = x * y / gcd(x,y);
    ll ans = N*(N+1)/2 - x * (N/x)*(N/x + 1) / 2 - y * (N/y)*(N/y + 1) / 2 + lcm  * (N/lcm)*(N/lcm + 1) / 2;
    cout << ans << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}