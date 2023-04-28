#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

int main(int argc, char*argv[]){
    ll n;
    cin >>n;
    bool arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
    if(n*(n+1)%4!=0){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        ll num = 0, sum = (n*(n+1))/4;
        ll max = n;
        while(sum>0){
            if(sum >= max){
                arr[max-1]= 1;
                num++;
                sum = sum - max;
                max--;
            }
            else{
                arr[sum-1] = 1;
                num++;
                sum = 0;
            }
        }
        cout << num << endl;
        for(int i = 0; i < n; i++){
            if(arr[i]) cout << i+1 << " ";
        }
        cout << endl << n-num << endl;
        for(int i = 0; i < n; i++){
            if(!arr[i]) cout << i+1 << " ";
        }
        cout << endl;
    }
}