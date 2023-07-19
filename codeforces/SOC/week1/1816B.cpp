#include<bits/stdc++.h>
#include<limits.h>

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define ppll pair<pll,pll>
#define ull unsigned long long


template <typename T>
void printArr(T* arr, ll n){
    cout << endl << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    cout << endl << endl;
}


void solve(){
    ll n;
    cin >> n;
    ll max = 2*n, min =2;
    for(int i = 1; i <= n; i++){
        if((i+1)%2 == 0){
            cout << max << " ";
            max-=2;
        }
        else{
            cout << min << " ";
            min+=2;
        }
    }
    cout << endl;
    max = n+1;
    min = 1;
    for(int i = 1; i <= n; i++){
        if(i%2 == 0){
            cout << max << " ";
            max+=2;
        }
        else{
            cout << min << " ";
            min+=2;
        }
    }
    return;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}