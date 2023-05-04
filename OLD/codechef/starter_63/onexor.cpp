#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n+2];
    for(int i = 0; i < n+2;i++){
        arr[i] = 0;
    }
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        arr[num]++;
    }
    int mymax = 0;
    for(int i = 0; i<=n; i=i+2){
        mymax = max(mymax, arr[i]+arr[i+1]);
    }
    cout << n - mymax << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}