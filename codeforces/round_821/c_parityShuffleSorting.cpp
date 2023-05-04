#include<bits/stdc++.h>
using namespace std;

void swap(int* a,int l, int r){
    if((a[l]+a[r])%2){
        a[r] = a[l];
    }
    else{
        a[l] = a[r];
    }
}

int main(int argc, char*argv[]){

}
