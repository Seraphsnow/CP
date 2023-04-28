#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(int argc, char*argv[]){
    string str;
    cin >> str;
    int curr = 1, prev = 1, i = 1;
    while(str[i] != '\0'){
        if(str[i] == str[i-1]){
            curr++;
        }
        else{
            prev = max(curr, prev);
            curr = 1;
        }
        i++;
    }
    prev = max(curr,prev);
    cout << prev << endl;
}