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
    ifstream myfile("day3.txt");
    string mystring;
    ll score = 0;
    if(myfile.is_open()){
        while(myfile){
            bool found = false;
            if(myfile.eof()) break;
            getline(myfile, mystring);
            if(mystring.size()%2 != 0) cout << "J" << endl;
            for(int i = 0; i < mystring.size()/2; i++){
                char mychar = mystring[i];
                for(int i = mystring.size()/2; i <mystring.size(); i++){
                    if(mystring[i] == mychar){
                        if(mychar > 96){
                            score += mychar-96;
                        }
                        else{
                            score += mychar - 64 + 26;
                        }
                        found = true;
                    }
                    if(found) break;
                }
                if(found) break;
            }
        }
        cout << score << endl;
    }
}