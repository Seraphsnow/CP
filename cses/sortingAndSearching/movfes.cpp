#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>

bool comp(pll a, pll b){
    return a.se < b.se;
}

int main(int argc, char*argv[]){
    int n;
    cin >> n;
    priority_queue<ll> exit;
    pll time[n];

    for(int i = 0; i < n; i++){
        cin >> time[i].fi >> time[i].se;
    }
    sort(time, time+n, comp);
    ll index = 0;
    ll ans = 0;
    while(true){
        if(index == n) break;
        ans++;
        ll endtime = time[index].se;
        index++;
        if(index == n) break;
        while(true){
            if(time[index].fi < endtime){
                index++;
            }
            else{
                break;
            }
            if(index == n){
                break;
            }
        }
    }
    cout << ans << endl;
}