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


class Compare{
    public:
        bool operator()(pll above, pll below){
            return above.se < below.se;
        }
};

int main(int argc, char*argv[]){
    ll x,n;
    cin >> x >>n;
    priority_queue<pll, vector<pll>, Compare> p1;
    p1.push({x,0});
    p1.push({0,x});
    //cout << p1.top().fi << endl;
    vector<ll> lights;
    set<ll> left;
    for(int i = 0; i < n; i++){
        ll light;
        cin >> light;
        left.insert(light);
        while(true){
            pll top = p1.top();
            auto it = left.upper_bound(top.fi);
            if( it != left.end() && *it < top.fi+top.se){
                p1.pop();
                p1.push({top.fi, *it-top.fi});
                p1.push({*it, top.se + top.fi - *it});
                left.erase(*it);
            }
            else{
                break;
            }
        }
        cout << p1.top().se << " ";
    }
    cout << endl;
}