#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        long int n, ans=0;
        cin >> n;
        ans+=n%10;
        while(n>=10){
            n = n/10;
        }
        ans+=n;
        cout << ans << endl;
    }
}