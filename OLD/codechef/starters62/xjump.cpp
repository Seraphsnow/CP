#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y;
    cin >> x >> y;
    cout << (x/y + x%y) << "\n";
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}