#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(int argc, char*argv[]){
    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++){
        char arr[51];
        for(int k = 0; k < 51;k++){
            arr[k] = '1';
        }
        int size;
        cin >> size;
        int numArr[size];
        for(int j = 0; j < size; j++){
            cin >> numArr[j];
        }
        string mystring;
        cin >> mystring;
        bool yes = true;
        for(int l = 0; l < size; l++){
            if(arr[numArr[l]] == '1') arr[numArr[l]] = mystring[l];
            else{
                if(arr[numArr[l]] != mystring[l]){
                    yes = false;
                    break;
                }
            }
        }
        if(yes) cout << "YES\n";
        else cout << "NO\n";
    }

}