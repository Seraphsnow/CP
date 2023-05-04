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

vector<string> adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> mystring;
    while (!ss.eof()) {
        getline(ss, word, del);
        mystring.pb(word);
    }
    return mystring;
}

ll mod = 23*19*13*17;

ll inspect0(ll worry){
    return worry*19;
}

ll inspect1(ll worry){
    return worry+6;
}

ll inspect2(ll worry){
    return worry*worry;
}

ll inspect3(ll worry){
    return worry+3;
}

int test0(ll worry){
    if(worry%23 == 0) return 2;
    else return 3;
}

int test1(ll worry){
    if(worry%19 == 0) return 2;
    else return 0;
}

int test2(ll worry){
    if(worry%13 == 0) return 1;
    else return 3;
}

int test3(ll worry){
    if(worry%17 == 0) return 0;
    else return 1;
}

int main(int argc, char*argv[]){
    vector<ll> monkey[8];
    int inspect[8];
    monkey[0].pb(79);
    monkey[0].pb(98);
    monkey[1].pb(54);
    monkey[1].pb(65);
    monkey[1].pb(75);
    monkey[1].pb(74);
    monkey[2].pb(79);
    monkey[2].pb(60);
    monkey[2].pb(97);
    monkey[3].pb(74);
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < monkey[j].size();){
                ll worry = monkey[j][k];
                inspect[j]++;
                if(j == 0) worry = inspect0(worry);
                if(j == 1) worry = inspect1(worry);
                if(j == 2) worry = inspect2(worry);
                if(j == 3) worry = inspect3(worry);
                int newmonkey;
                worry = worry % mod;
                if(j == 0) newmonkey = test0(worry);
                if(j == 1) newmonkey = test1(worry);
                if(j == 2) newmonkey = test2(worry);
                if(j == 3) newmonkey = test3(worry);
                monkey[newmonkey].pb(worry);
                monkey[j].erase(monkey[j].begin()+k);
            }
        }
    }
    for(int i = 0; i < 4; i++){
        cout << inspect[i] << endl;
    }
}