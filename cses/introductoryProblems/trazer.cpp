#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll ans = 0;
    while(n>0){
        n = n/5;
        ans += n;
    }
    cout << ans << endl;
}