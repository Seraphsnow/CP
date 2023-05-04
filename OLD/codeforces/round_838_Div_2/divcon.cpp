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
    ll arr[n], sum = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum%2 == 0){
        cout << 0 << endl;
        return;
    }
    ll min = 9999;
    for(int i = 0; i < n; i++){
        bool odd = arr[i]%2;
        for(int j = 1; true; j++){
            arr[i] = arr[i]/2;
            if(arr[i]%2 != odd){
                if(j < min){
                    min = j;
                }
                break;
            }
        }
        if(min == 1){
            cout << 1 << endl;
            return;
        }
    }
    cout << min << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}