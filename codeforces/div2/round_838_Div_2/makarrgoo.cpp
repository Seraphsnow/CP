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
        cout << i << ": " << arr[i].fi << endl;
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

bool comparator(pll p1, pll p2){
    return p1.fi < p2.fi;
}

void solve(){
    ll n;
    cin >> n;
    pll arr[n];
    for(int i = 0; i < n; i++){
        int ai;
        cin >> ai;
        arr[i] = {ai, i+1};
    }
    sort(arr, arr+n, comparator);
    vector<pll> operations;
    for(int i = 0; i < n-1; i++){
        if(arr[i+1].fi%arr[i].fi == 0){
            continue;
        }
        else{
            ll k = arr[i+1].fi/arr[i].fi;
            operations.pb({arr[i+1].se, (k+1)*arr[i].fi - arr[i+1].fi});
            arr[i+1].fi = (k+1)*arr[i].fi;
        }
    }
    cout << operations.size() << endl;
    for(int i=0;i<operations.size(); i++){
        cout << operations[i].fi << " " << operations[i].se << endl; 
    }
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}