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
    ll n,m,k;
    cin >> n >> m >> k;
    ll arr[m];
    bool possible = true;
    ll numceil = 0;
    for(ll i = 0; i < m; i++){
        cin >> arr[i];
        if(possible){
            if(arr[i] > ceil(1.0*n/k)){
                possible = false;
            }
            else if(arr[i] == ceil(1.0*n/k)){
                numceil++;
            }
            if(numceil > (n % k) && n%k != 0){
                possible = false;
            }
        }
    }
    if(possible) cout << "YES\n";
    else cout << "NO\n";
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}