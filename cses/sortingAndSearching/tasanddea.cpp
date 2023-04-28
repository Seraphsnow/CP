#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>

bool comp(pll p1, pll p2){
    return p1.fi < p2.fi;
}
int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    pll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].fi >> arr[i].se;
    }
    sort(arr, arr+n, comp);
    ll ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum+=arr[i].fi;
        ans+=arr[i].se;
        ans-=sum;
    }
    cout << ans << endl;

}