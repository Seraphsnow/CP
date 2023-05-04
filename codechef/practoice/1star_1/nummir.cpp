#include<bits/stdc++.h>
using namespace std;

int divBy(int k, long long int n){
    if(n%k == 0) return 1;
    else return 0;
}

int main(int argc, char*argv[]){
    int n,k,nums = 0;
    cin >> n >> k;
    while(n--){
        long long int num;
        cin >> num;
        nums += divBy(k,num);
    }
    cout << nums << endl;
}