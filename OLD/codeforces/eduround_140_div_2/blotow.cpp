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
    vector<ll> heights;
    ll height;
    cin >> height;
    heights.pb(height);
    for(ll i = 1; i < n; i++){
        ll height;
        cin >> height;
        if(height>heights[0]){
            heights.pb(height);
        }
    }
    sort(heights.begin(), heights.end());
    for(ll i = 1; i < heights.size(); i++){
        ll height = heights[i];
        heights[0] = (height - heights[0]+1)/2 + heights[0];
    }
    cout << heights[0] << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}