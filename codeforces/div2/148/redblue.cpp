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

template <typename T>
T gcd(T a, T b){
    if(a%b == 0){
        return b;
    }
    else{
        return gcd(b, a%b);
    }
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

bool comp(pll p1,pll p2){
    return p1.fi < p2.fi;
}

int main(int argc, char*argv[]){
    ll n,q;
    cin >> n >> q;
    vector<ll> arr;
    for(int i = 1; i<=n; i++){
        ll num;
        cin >> num;
        arr.pb(num);
    }
    sort(arr.begin(), arr.end());
    ll mins[2*n];
    for(int i = 1; i <= n; i++){
        ll currmin = arr[0]+i;
        for(int j = 1; j <i;j++){
            currmin = min<ll>(currmin, arr[j] + i-j);
        } 
        if(i != n){
            currmin = min<ll>(currmin, arr[i]);
        }
        mins[i-1] = currmin;
    }
    ll arr2[n];
    for(int i = 0; i < n; i++){
        
    }

}