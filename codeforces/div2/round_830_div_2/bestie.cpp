#include<bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b){
    if(a == b) return b;
    if(a%b == 0) return b;
    else return gcd(b, a%b);
}

void solve(){
    long long int numgcd;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        long long int num;
        cin >> num;
        if(i == 0) numgcd = num;
        else numgcd = gcd(num, numgcd);
    }
    if(numgcd == 1) cout << "0\n";
    else if(gcd(numgcd, n) == 1) cout << "1\n";
    else if(gcd(numgcd,n-1) == 1) cout << "2\n";
    else cout << "3\n";
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}