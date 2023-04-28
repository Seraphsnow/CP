#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    for(ll i = 0; i <t; i++){
        ll ans = (i*i*i*i-3*i*i)/2 + 2*i*i*i+5*i;
        cout << ans << endl;
    }
}