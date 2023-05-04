#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    char num[n];
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        cin >> num[i];
        if(i != 0){
            if(num[i-1]!= num[i]) ans++;
        }
    }
    if(ans == 0) cout << ans << endl;
    else if (num[0] == '0') cout << ans -1 << endl;
    else cout << ans << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}