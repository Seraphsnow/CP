#include<bits/stdc++.h>
using namespace std;

class data{
    public:    
        int red, blue;
        data(int red, int blue){
            this->blue = blue;
            this->red = red;
        }
        data(){}

};


void solve(){
    int n;
    cin >> n;
    int r[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> r[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }


}

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++){
        solve();
    }
}