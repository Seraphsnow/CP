#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, odd = 0;
    cin >> n;
    while(n--){
        long long int a;
        cin >> a;
        if(a%2) odd++;
    }
    if(odd%2 == 0 && odd > 0) cout << "YES\n";
    else cout << "NO\n";
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}