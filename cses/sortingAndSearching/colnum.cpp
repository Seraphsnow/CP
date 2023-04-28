#include<bits/stdc++.h>
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
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr, arr+n, comp);
    ll rounds = 1, prev = arr[0].se;

    for(int i = 1; i < n; i++){
        if(arr[i].se > prev){
            prev = arr[i].se;
        }
        else{
            prev = arr[i].se;
            rounds++;
        }
    }
    cout << rounds << endl;
}