#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll myplus(ll a,ll b){
    ll c = a+b;
    return c;
}

ll sum(){
    int n,k;
    cin >> n >> k;
    int x = ceil(1.0*n/k);
    ll arr[k][x];
    for(int i = 0; i < n; i++){
        ll input;
        cin >> input;
        arr[i%k][i/k] = input;
    }
    for(int i = n; i < k*x;i++){
        arr[i%k][i/k] = 0;
    }
    ll ans=0;
    for(int i = 0; i < k; i++){
        ans += *max_element(arr[i], arr[i]+x);
    }
    return ans;
}

int main(int argc, char* argv[]){
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++) cout << sum() << "\n";
}