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

bool comp(pll p1, pll p2){
    return p1.fi > p2.fi;
}

ll solve(){
    ll n;
    cin >> n;
    if(n == 0){
        return -1;
    }
    vector<pll> heights;

    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        heights.pb({num,i});
    }
    set<ll> elems;
    sort(heights.begin(), heights.end(), comp);
    ll maxArea = heights[0].fi;
    elems.insert(heights[0].se);
    elems.insert(heights[0].se-1);

    for(int i = 1; i < n; i++){
        bool leftin = elems.find(heights[i].se) != elems.end(), rightin = elems.find(heights[i].se-1) != elems.end();
        ll width = 1;
        if(leftin && rightin){
            ll left = *(--elems.lower_bound(heights[i].se));
            ll right = *(elems.upper_bound(heights[i].se));
            elems.erase(heights[i].se);
            elems.erase(heights[i].se+1);
            maxArea = max(maxArea, (right-left)*heights[i].fi);
        }
        else if(leftin){
            ll left = *(--elems.lower_bound(heights[i].se));
            elems.erase(heights[i].se);
            elems.insert(heights[i].se+1);
            maxArea = max(maxArea, (heights[i].se+1-left)*heights[i].fi);
        }
        else if(rightin){
            ll right = *(elems.upper_bound(heights[i].se));
            elems.insert(heights[i].se);
            elems.erase(heights[i].se+1);
            maxArea = max(maxArea, (right-heights[i].se)*heights[i].fi);
        }
        else{
            elems.insert(heights[i].se+1);
            elems.insert(heights[i].se);
            maxArea=max(maxArea, heights[i].fi);
        }
        
    }
    return maxArea;
    
}

int main(int argc, char*argv[]){
    
    while(true){
        
        ll ans = solve();
        if(ans == -1){
            return 0;
        }
        else{
            cout << ans << endl;;
        }
    }
}