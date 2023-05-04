#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int q=0,a=0;
    char input1;
    cin >> input1;
    bool answering = true;
    if(input1 == 'A'){
        cout << "No\n";
        return;
    }
    else{
        q++;
    }
    for(int i = 1; i < n; i++){
        char input;
        cin >> input;
        if(input == 'Q'){ q++;answering = true;}
        else if(answering){
            a++;
        }
        if(a == q) answering = false;
    }
    if(q>a) cout << "No\n";
    else cout << "Yes\n";
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}