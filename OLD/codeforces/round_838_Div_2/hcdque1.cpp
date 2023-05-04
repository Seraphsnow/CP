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

int solve(ll length, ll* arr){
    if(length <=5){
        for(int i = 1; i <= length ; i++){
            for(int j = i+1; j <= length; j++){
                cout << "? " << arr[i] << " " << arr[j] << endl;
                cout.flush();
                ll mygcd;
                cin >> mygcd;
                if(mygcd == 1){
                    cout << "! " << arr[i] << " " << arr[j] << endl;
                    return 0;
                }
            }
        }
    }
    pll gcdarr[length];
    vector<ll> indices;
    ll maxgcd = 0;
    for(int i = 1; i < length; i++){
        cout << "? " << arr[0] << " " << arr[i] << endl;
        cout.flush();
        ll mygcd;
        cin >> mygcd;
        if(mygcd>maxgcd){
            maxgcd = mygcd;
            indices.clear();
            indices.pb(arr[i]);
        }
        else if(mygcd == maxgcd){
            indices.pb(arr[i]);
        }
    }
    if(maxgcd == 1){
        cout << "! 2 3" << endl;
    }
    else{
        ll maxgcd2 = 0;
        ll index = 0;
        for(int i = 0; i < indices.size(); i++){
            cout << "? " << maxgcd << " " << indices[i] << endl;
            cout.flush();
            ll mygcd;
            cin >> mygcd;
            if(mygcd > maxgcd2){
                maxgcd2 = mygcd;
                index = indices[i];
            }
        }
        cout << "! " << maxgcd << " " << index << endl;
    }

}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll arr[n];
        for(int i = 1; i <= n; i++){
            arr[i] = i;
        }
        if(n == 1){
            cout << "! 1 1" << endl;
            continue;
        }
        if(n == 2){
            cout << "! 1 2" << endl;
        }

        int a = solve(n, arr);
        if(a == -1){
            return 0;
        }
    }
}