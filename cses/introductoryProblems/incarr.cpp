#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll prev;
    cin >> prev;
    ll ans = 0;
    for(int i = 0; i < n-1; i++){
        ll num;
        cin >> num;
        if(num < prev){
            ans += prev-num;
        }
        else prev = num;
    }
    cout << ans << endl;
}