#include<bits/stdc++.h>
using namespace std;

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    if((a+b)%2 == 1 ||(c+b)%2 == 1 ||(a+c)%2 == 1 ){
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