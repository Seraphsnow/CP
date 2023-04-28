#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){
    ll y,x;
    cin >> y >> x;
    if(y > x){
        if(y%2){
            cout << (y-1)*(y-1) + x;
        }
        else{
            cout << (y)*y + 1 - x;
        }
    }
    else{
        if(x%2){
            cout << x*x + 1 - y;
        }
        else{
            cout << (x-1)*(x-1) + y;
        }
    }
    cout << endl;
    return;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}