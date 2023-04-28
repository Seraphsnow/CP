#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>
int main(int argc, char*argv[]){
    ll n, k;
    cin >> n >> k;
    pll nums[n];
    for(int i = 0; i < n; i++){
        nums[i].fi = i+1;
    }
    ll index = 0,b = k%n, a = k/n;
    for(int i = 0; i < k; i++){
        index = (index + b) % n;

    }
}