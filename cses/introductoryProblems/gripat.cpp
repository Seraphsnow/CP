#include <bits/stdc++.h>
#include <limits.h>
// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>
#define ppll pair<pll, pll>
#define ull unsigned long long

template <typename T>
void printArr(T *arr, ll n)
{
    cout << endl
         << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl
         << endl;
}

class path
{
public:
    string mystr;
    bool** arr;
    ll numU, numL,numD, numR, numvisit;
    
    path(string str, ll u, ll l ,ll d, ll r, ll n, bool ** arr1)
    {
        numU = u;
        numL = l;
        numD = d;
        numR = r;
        mystr = str;
        numvisit = n;
        
    }

};

bool partValid(path str){
    if(str.mystr.size() != 48){

    }
}

int main(int argc, char *argv[])
{
    string inp;
    cin >> inp;
    vector<path> strings;
    path emptyPath("",0,0,0,0);
    strings.push_back(emptyPath);
    for(int i = 0; i < 48; i++){
        vector<path> newStrings = strings;
        strings.clear();
        for(int j = 0; j < newStrings.size(); j++){
            path newp(newStrings[i].mystr+"U");
            if(partValid(newp))
        }
    }
}