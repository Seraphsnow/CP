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

template <typename T>
void printVector(vector<T> arr)
{
    cout << endl
         << endl;
    for (ll i = 0; i < arr.size(); i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
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
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll max, min;
    if(s[0] == '0'){
        min = 1;
        max = 1;
    }
    else{
        min = 2;
        max = 2;
    }
    cout << 1 << " ";
    for(int i = 1; i < n-1; i++){
        if(s[i] == '0'){
            min = 1;
            cout << max-min+1 << " ";
        }
        else{
            max = i+2;
            min++;
            cout << max - min + 1 << " ";
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