#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n,x,y;
    cin >> n >>x >> y;
    if(y%x == 0){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}


int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}