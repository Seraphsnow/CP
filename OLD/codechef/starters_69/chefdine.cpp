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
    ll n, k;
    cin >> n >> k;
    ll a[n], b[n];
    map<ll,ll> hashmap;
    ll index = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(hashmap.find(a[i]) == hashmap.end()){
            hashmap[a[i]] = index;
            index++;
        }
    }
    for(int i = 0; i < n ; i++){
        cin >> b[i];
    }
    if(index < k){
        cout << -1 << endl;
        return;
    }
    ll arr[index];
    for(int i = 0; i < index; i++){
        arr[i] = 1000000;
    }
    for(int i = 0; i < n; i++){
        if(b[i] < arr[hashmap[a[i]]]){
            arr[hashmap[a[i]]] = b[i];
        }
    }
    sort(arr, arr+index);
    ll sum = 0;
    for(int i = 0; i < k; i++){
        sum+=arr[i];
    }
    cout << sum << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}