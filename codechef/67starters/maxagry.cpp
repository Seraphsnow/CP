#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int n,k;
    cin >> n >> k;
    if(k>n/2){
        cout << n*(n-1)/2 << endl;
    }
    else{
        cout << k*(2*n-2*k-1) << endl;
    }
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}