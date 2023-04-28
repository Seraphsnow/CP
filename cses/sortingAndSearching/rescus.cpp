#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>

bool comp(pll a, pll b){
    return a.fi < b.fi || (a.fi == b.fi && a.se < b.se);
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
    ll mymax = 0;
    for(int i = 0; i < n; i++){
        ll currtime = time[i].fi;
        exit.push(-time[i].se);
        while(true){
            if(exit.top() > -1*currtime){
                exit.pop();
            }
            else{
                break;
            }
        }
        ll size = exit.size();
        mymax = max(mymax, size);
    }
    cout << mymax << endl;
}