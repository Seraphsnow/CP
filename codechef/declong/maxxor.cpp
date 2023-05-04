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

void adv_tokenizer(string s, char del)//Split string
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        cout << word << endl;
    }
}

void solve(){
    string s0, s1;
    cin >> s0 >> s1;
    int count[2][2];
    count[0][0] = 0;
    count[0][1] = 0;
    count[1][0] = 0;
    count[1][1] = 0;
    
    for(int i = 0; i < s1.size(); i++){
        if(s0[i] == '0'){
            count[0][0]++;
        }
        else{
            count[0][1]++;
        }
        if(s1[i] == '0'){
            count[1][0]++;
        }
        else{
            count[1][1]++;
        }
    }
    int num1 = min(count[1][0], count[0][1]) + min(count[1][1], count[0][0]);
    for(int i = 0; i < s1.size(); i++){
        if(i < num1){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    cout << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}