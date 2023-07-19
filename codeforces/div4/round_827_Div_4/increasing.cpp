#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){

    int testcases;
    cin >> testcases;
    for(int i = 0; i < testcases; i++){
        int* array;
        int size;
        cin >> size;
        array = new int[size];
        for(int j = 0; j < size; j++){
            cin >> array[j];
        }
        sort(array, array+size);
        bool no = 0;
        for(int k = 0; k < size-1; k++){
            if(array[k] == array[k+1]){
                cout << "NO\n";
                no = 1;
                break;
            }
        }
        if(!no) cout << "YES\n";
    }
}