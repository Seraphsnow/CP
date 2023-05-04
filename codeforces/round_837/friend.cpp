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
    int n,m;
    cin >> n >> m;
    int arr[n+1];
    for(int i =1 ; i < n+1; i++){
        arr[i] = n+1;
    }
    for(int i = 0; i <m; i++){
        int a ,b;
        cin >> a >> b;
        if(a>b){
            if(a<arr[b]){
                arr[b] = a;
            }
        }
        else{
            if(b < arr[a]){
                arr[a] = b;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ll max = arr[i], num = i;
        for(int j = i+1; j < max; j++){
            if(arr[j]<max){
                max = arr[j];
                num = j;
            }
        }
        ans+=max*(num-i+1) - num*(num+1)/2 + i*(i-1)/2;
        i = num;
    }
    cout << ans << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}