#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>

bool comparator(pll p1, pll p2){
    return p1.fi < p2.fi;
}

int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll x;
    cin >> x;
    pll arr[n];
    for(int i = 0; i <n; i++){
        cin >> arr[i].fi;
        arr[i].se = i+1;
    }
    sort(arr, arr+n, comparator);
    for(int i = 0; i < n; i++){
        ll index1 = i+1;
        ll index2 = n-1;

        while(index2 > index1){
            if(arr[i].fi+arr[index1].fi+arr[index2].fi == x){
                cout << arr[i].se <<  " " << arr[index1].se << " " << arr[index2].se << endl;
                return 0;
            }
            else if(arr[i].fi+arr[index1].fi+arr[index2].fi > x) index2--;
            else index1++;
        }
    }
    cout << "IMPOSSIBLE\n";
}