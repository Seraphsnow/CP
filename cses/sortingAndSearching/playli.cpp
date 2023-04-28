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
    ll mymax = 1;
    set<ll> prev;
    ll num[n];
    cin >> num[0];
    prev.insert(num[0]);
    ll index = 0;
    for(int i = 1; i < n;i++){
        cin >> num[i];
        if(prev.count(num[i]) == 1){
            mymax = max<ll>(mymax, prev.size());
            while(num[index] != num[i]){
                prev.erase(num[index]);
                index++;
            }
            index++;
        }
        else{
            prev.insert(num[i]);
        }
    }
    cout << max<ll>(mymax, prev.size()) << endl;
}