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

void solve(){
    ll n;
    cin >> n;
    bool zeros[10], ones[10];
    for(int i = 0; i < 10; i++){
        zeros[i]= 0;
        ones[i] = 0;
    }
    for(int i = 0; i < n; i++){
        ll num;
        cin >> num;
        
        for(int i = 0; i < 10; i++){
            if(num%2 == 0){
                zeros[i] = 1;
            }
            else{
                ones[i] = 1;
            }
            num = num/2;
        }
    }
    ll ans = 0;
    for(int i = 9;i>=0;i--){
        ans = ans*2;
        if(zeros[i] && ones[i]){
            ans++;
        }
        
    }
    // printArr<bool>( zeros, 10);
    // printArr<bool>( ones, 10);
    cout << ans << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}