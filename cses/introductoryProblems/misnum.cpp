#include<bits/stdc++.h>
using namespace std;


int main(int argc, char*argv[]){
    int n;
    cin >> n;
    bool arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
    for(int i = 0; i < n-1;i++){
        int num;
        cin >> num;
        arr[num-1] = 1;
    }
    for(int i = 0; i < n; i++){
        if(!arr[i]) cout << i+1<< endl;
    }
    return 0;
}