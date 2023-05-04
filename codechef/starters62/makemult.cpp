#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int a, b;
    cin >> a >> b;
    if(b-2*a>=0 || b == a) cout << "YES\n";
    else cout << "NO\n";
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}