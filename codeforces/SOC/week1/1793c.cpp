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
    cin >> n;
    pll arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].fi;
        arr[i].se = i;
    }
    sort(arr, arr+n, comp);
    ll l = 0, r = n-1, indexfront = 0, indexback = n-1;

    while(l<=r){
        if(arr[indexfront].se == l){
            indexfront++;
            l++;
        }
        else if(arr[indexfront].se == r){
            indexfront++;
            r--;
        }
        else if(arr[indexback].se == l){
            l++;
            indexback--;
        }
        else if(arr[indexback].se == r){
            r--;
            indexback--;
        }
        else{
            cout << l+1 << " " << r+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}