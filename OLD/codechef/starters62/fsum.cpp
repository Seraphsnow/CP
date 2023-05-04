#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;
    cin >> n >> q;
    long long int sum =0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        sum += num;
    }
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        sum += (1-(r-l)%2);
    }
    cout << sum << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}