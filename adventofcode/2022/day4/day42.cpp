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
    ifstream myfile("day4.txt");
    string mystring;
    ll pairs=0;
    if(myfile.is_open()){
        while(myfile){
            if(myfile.eof()) break;
            getline(myfile, mystring);
            vector<string> mystrings = adv_tokenizer(mystring, ',');
            vector<string> num1s = adv_tokenizer(mystrings[0],'-');
            vector<string> num2s = adv_tokenizer(mystrings[1],'-');
            ll num11 = stoi(num1s[0]), num12=stoi(num1s[1]), num21=stoi(num2s[0]), num22=stoi(num2s[1]);
            if(!((num11 > num22) || (num12<num21))) pairs++;
        }
        cout << pairs << endl;
    }
}