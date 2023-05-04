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

vector<string> adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> mystring;
    while (!ss.eof()) {
        getline(ss, word, del);
        mystring.pb(word);
    }
    return mystring;
}

int main(int argc, char*argv[]){
    ifstream myfile("day3.txt");
    string mystring1 = "", mystring2= "";
    ll score = 0;
    if(myfile.is_open()){
        ll index = 1;
        while(myfile){
            if(myfile.eof()) break;
            if(mystring1==""){
                getline(myfile, mystring1);
            }
            else if(mystring2 == ""){
                getline(myfile, mystring2);
            }
            else{
                for(int i = 0; i < min(mystring1.size(), mystring2.size()); i++){
                    
                }

                mystring1 = "";
                mystring2 = "";
                index++;
            }

        }
    }
}