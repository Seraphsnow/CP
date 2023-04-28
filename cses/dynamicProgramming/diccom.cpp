#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>

#define MOD 1000000007
int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll arr[max<ll>(n,6)];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;
    arr[3] = 8;
    arr[4] = 16;
    arr[5] = 32;
    for(int i = 6; i < n; i++){
        arr[i] = 0;
        for(int j = 1; j <=6;j++){
            arr[i]+=arr[i-j];
        }
        arr[i] = arr[i] % MOD;
    }
    cout << arr[n-1] << endl;
}