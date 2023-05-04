#include<bits/stdc++.h>
using namespace std;

int mymod(int a){
    if(a<0){
        int a1 = -a/26;
        int ans = 26+a+a1;
        return ans;
    }
    else{
        return a - (a/26)*26;
    }
}

void solve(){
    int n;
    cin >> n;
    string s1,s2;
    cin >> s1>>s2;
    int sum = 0;
    for(int i = 0; i < n;i++){
        sum += s1[i]-s2[i];
    }
    
    int ans = mymod(sum);
    cout << min(ans, 26-ans) << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}