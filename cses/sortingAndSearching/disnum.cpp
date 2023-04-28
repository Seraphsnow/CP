#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

int main(int argc, char*argv[]){
    int n;
    cin >> n;
    set<ll> nums;
    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        nums.insert(num);

    }
    cout << nums.size();
}