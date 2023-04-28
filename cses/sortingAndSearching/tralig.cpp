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
#define ull unsigned long long

int main(int argc, char*argv[]){
    ll x,n;
    cin >> x >>n;
    priority_queue<pll> p1;
    p1.push({x,0});
    vector<ll> lights;

    for(int i = 0; i < n; i++){
        ll light;
        cin >> light;
        pll pair = p1.top();
        for(int j = 0; j < lights.size();j++){
            
        }
    }
}