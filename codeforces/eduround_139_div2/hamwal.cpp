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
    ll n;
    cin >> n;
    string up, down;
    cin >> up >> down;
    for(int i = 0; i < n-1; i++){
        if(up[i] != up[i+1] && down[i] != down[i+1]){
            cout << "NO\n";
            return;
        }
    }
    ll length = 0;
    for(int i = 0; i < n; i++){
        if(up[i] == down[i]){
            length++;
        }
        else{
            if(i - length - 1 < 0){}
            else if(length%2 == 1){
                if(up[i]!= down[i-length-1]){
                    cout << "NO\n";
                    return;
                }
            }
            else{
                if(up[i] != up[i-length-1]){
                    cout << "NO\n";
                    return;
                }
            }
            length = 0;
        }
    }
    
    cout << "YES\n";
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}