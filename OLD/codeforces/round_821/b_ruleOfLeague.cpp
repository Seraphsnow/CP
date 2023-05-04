#include<bits/stdc++.h>
using namespace std;

void champions(){
    int n,x,y;
    cin >> n >> x >> y;
    int myx = max(x,y);
    if(x*y != 0 || (x == 0 && y == 0) || ((n-1)%myx != 0)){ 
        cout << "-1" << endl;
        return;
    }
    else{
        for(int i = 0; i < n-1; i++){
            cout << 2+(i/myx)*myx << " ";
        }
    }
    cout << endl;
}

int main(int argc, char*argv[]){
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++) champions();
}