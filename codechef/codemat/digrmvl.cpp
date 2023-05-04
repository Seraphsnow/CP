#include<bits/stdc++.h>
using namespace std;

long long int mymod = 1000000007;

void solve(){
    long long int ans = 0, pow11 = 1;
    string n;
    cin >> n;
    for(int i = n.length()-1; i >-1; i--){
        long long int num = n[i]-48;
        ans = (ans *  2 + num * pow11)%mymod;
        pow11 = (pow11 *11)%mymod;
    }
    ans = ans %mymod;
    cout << ans << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}