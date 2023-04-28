#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>
int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll maxsum, maxend;
    cin >> maxsum;
    maxend = maxsum;
    for(int i = 1; i < n; i++){
        ll a;
        cin >> a;
        maxend+=a;
        maxend= max(a, maxend);
        maxsum = max(maxsum, maxend);
    }
    cout << maxsum << endl;
}