#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        long int n, ans =0;
        cin >> n;
        while(n > 0){
            ans = ans*10;

            ans+= n%10;
            n = n/10;
        }
        cout << ans << endl;
    }
}