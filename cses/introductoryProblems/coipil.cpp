#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

void solve(){
    ll a,b;
    cin >> a >> b;
    ll mymin = min(a,b), mymax = max(a,b);
    a = mymin;
    b = mymax;
    if(2*a-b < 0 || (2*a-b)%3 != 0){
        cout << "NO\n";
    }
    else{ cout << "YES\n";}
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}