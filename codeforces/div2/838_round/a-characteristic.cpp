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

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        vector<pair<ll*,pair<pll,ll>>> arrays;
        ll * elem;
        elem = new ll [n];
        elem[0] = 1;
        arrays.push_back({elem,{{1,0},0}});
        for(int i = 1; i < n; i++){
            if(arrays.size()== 0){
                break;
            }
            for(int j = 0; j< arrays.size(); j++){
                ll* elem1;
                ll prevk = arrays[i].se.se;
                ll k1 = prevk+arrays[i].se.fi.fi, k2 = prevk + arrays[i].se.fi.se;
                if(k1 <= k){
                    arrays[j].fi[i] = 1;
                    arrays[j].se.se = k1;
                    arrays[j]
                }
            }
        }
        if(arrays.size()==0){
            cout << "NO\n" ;
        }
        else{
            cout << "YES\n";
            for(int i = 0; i < n;i++){
                cout << arrays[0].fi[i] << " ";
                
            }
            cout << endl;
        }
    }
}