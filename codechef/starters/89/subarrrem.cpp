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

bool comp(pll p1, pll p2){
    return p1.fi > p2.fi;
}
void solve(){
    ll n;
    cin >>n;
    pll a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a, a+n, comp);
    ll minIndex = 0, maxIndex = n-1;
    ll arr[n+1];
    for(int i = 0; i <=n; i++){
        arr[i] = i;
    }
    ll numinterv = 0, ans = 0;
    for(int i = 0; i < n-1; i++){
        ll num = a[i].fi, index = a[i].se;
        if(arr[index] == index){
            if(arr[index+1] == index+1){
                numinterv++;
            }
            arr[index] = arr[index+1];
            arr[arr[index+1]] = index;
        }
        else{
            if(arr[index+1] == index+1){
                arr[arr[index]] = index+1;
                arr[index+1] = arr[index];
            }
            else{
                numinterv--;
                arr[arr[index]] = arr[index+1];
                arr[arr[index+1]] = arr[index];
            }
        }
        if(numinterv == 1){
            ans = i+1;
        }
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