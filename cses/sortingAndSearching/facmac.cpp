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

template <typename T>
void printArr(T* arr, ll n){
    cout << endl << endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }
    cout << endl << endl;
}

ll num(ll* times, ll time, ll n){
    ll ans= 0;
    for(int i = 0; i < n; i++){
        ans+=time/times[i];
    }
    return ans;
}

int main(int argc, char*argv[]){
    ll n,t;
    cin >> n >> t;
    ll times[n];
    for(int i = 0; i < n; i++){
        cin >> times[i];
    }
    ll time = 1;
    while(num(times, time, n)< t){
        time=time*2;
    }
    ll time1 = time/2, time2 = time;
    time = (time1 + time2) / 2;
    ll ans = num(times,time,n);
    while(time2!=time1){
        if(ans< t){
            time1 = time;
        }
        else{
            time2 = time;
        }
        if(time2 == time1+1){
            if(num(times,time1,n)>=t){
                time = time1;

            }
            else{
                time = time2;
            }
            break;
        }
        time = (time1+time2)/2;
        ans = num(times,time,n);
        //cout << time << " " << ans << endl;
    }
    cout << time << endl;
}