#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int nx1 = min(x1, n+1-x1), 
        nx2 = min(x2, n+1-x2), 
        ny1 = min(y1, n+1-y1), 
        ny2 = min(y2, n+1-y2), 
        direct = abs(x1-x2) + abs(y1-y2);
    int ans = min(direct, min(nx1+nx2,min(nx1+ny2,min(ny1+nx2,ny1+ny2))));
    cout << ans << endl; 
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}