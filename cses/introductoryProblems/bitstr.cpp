#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

ll modulo= 1000000007;

int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll ans = 1, power2 = 2;
    while(n>=1){
        if(n%2 == 0){
            power2 = (power2*power2) % modulo;
        }
        else{
            ans = (ans * power2) % modulo;
            power2 = (power2*power2) % modulo;
        }
        n = n / 2;
    }
    cout << ans << endl;
}