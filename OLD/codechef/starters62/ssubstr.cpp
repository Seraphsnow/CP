#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    stack<char> order;
    char last;
    int num1=0;
    for(int i = 0; i < n; i++){
        char num;
        cin >> num;
        if(i == n-1){
            last = num;
        }
        if(order.empty() || order.top() != num){
            order.push(num);
            if(num == '1'){cout << "'HI"; num1++;}
        }
    }
    if(last == '1') cout << num1-1 << endl;
    else cout << num1 << endl;
}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}