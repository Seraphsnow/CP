#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin >> x;
    if(x>=30){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        solve();
    }
}