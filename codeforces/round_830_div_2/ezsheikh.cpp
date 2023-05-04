#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int n,q;
    cin >> n >> q;
    long long int arr[n];
    for(long long int i = 0; i < n; i++){
        cin >> arr[i];
    }
    while(q--){
        long long int L, R;
        cin >> L>>R;
        solvesmaller(L, arr+L-1, R-L+1);
    }
}

void solvesmaller(long long int shift, long long int * starting, long long int size){

}

long long int cost(long long int * arr, long long int length){
    long long int cost=0, sum, myxor ;

    for(int i = 0; i < length; i++){
        if(i == 0){
            sum = arr[i];
            myxor = sum; 
        }
        else{
            sum += arr[i];
            myxor = myxor^arr[i];
        }
        
    }
    
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}