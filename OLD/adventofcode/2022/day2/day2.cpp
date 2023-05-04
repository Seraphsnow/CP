#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

template <typename T>
void printArr(T*arr, ll size){
    cout << endl << endl;
    for(ll i = 0; i < size; i++){
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl << endl;
}


int main(int argc, char*argv[]){
    ifstream myfile("day2.txt");
    string myline;
    ll score = 0;
    // ABC rock, paper and scissor
    // XYZ rock, paper and scissor both respectively
    //lose 0, draw 3, win 6, 1 for X, 2 for Y, and 3 for Z
    if(myfile.is_open()){
        while(myfile){
            if(myfile.eof()) break;
            getline(myfile, myline);
            if(myline[0] == 'A'){
                if(myline[2] == 'X'){
                    score+=4;
                }
                else if(myline[2] == 'Y'){
                    score+=8;
                }
                else{
                    score+=3;
                }
            }
            else if(myline[0] == 'B'){
                if(myline[2] == 'X'){
                    score+=1;
                }
                else if(myline[2] == 'Y'){
                    score+=5;
                }
                else{
                    score+=9;
                }
            }
            else{
                if(myline[2] == 'X'){
                    score+=7;
                }
                else if(myline[2] == 'Y'){
                    score+=2;
                }
                else{
                    score+=6;
                }
            }
        } 
        cout << score << endl;
    }
}