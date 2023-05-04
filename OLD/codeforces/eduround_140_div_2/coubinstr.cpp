#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

ll mod = 998244353;

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

int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    ll arr[n+1][n+1];
    for(ll i = 1; i <=n; i++){
        for(ll j = i; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    ll s;
    if(arr[1][1] == 1) s = 1;
    else if(arr[1][1] == 2){
        cout << 0 << endl;
        return 0;
    }
    else{
        s = 2;
    }
    for(int i = 1; i<=n; i++){
        bool one= true, both = true, none = false;
        for(int j = 1; j<=i; j++){

        }
    }
}