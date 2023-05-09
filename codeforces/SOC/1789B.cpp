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
    string s;
    cin >> s;
    ll index1 = 0, index2 = n-1;
    ll numNeeded = 0;
    bool ongoing = false;
    while(index1<index2){
        if(!ongoing){
            if(s[index1] == s[index2]){
                index1++;
                index2--;
            }
            else{
                ongoing = true;
                numNeeded++;
                if(numNeeded == 2){
                    cout << "NO\n";
                    return;
                }
                index1++;
                index2--;
            }
        }
        else{
            if(s[index1] == s[index2]){
                ongoing = false;
                index1++;
                index2--;
            }
            else{
                index1++;
                index2--;
            }

        }
    }
    cout << "Yes\n";
}

int main(int argc, char*argv[]){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}