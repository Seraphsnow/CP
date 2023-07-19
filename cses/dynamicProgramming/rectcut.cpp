#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

//#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

template <typename T>
void printArr(T *arr, ll size)
{
    cout << endl
         << endl;
    for (ll i = 0; i < size; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
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
T gcd(T a, T b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

template <typename T>
T min3(T a, T b, T c){
    return min<T>(a,min<T>(b,c));
}

template <typename T>
T min4(T a, T b, T c, T d){
    return min<T>(min<T>(a,d),min<T>(b,c));
}

template <typename T>
T max3(T a, T b, T c){
    return max<T>(a,max<T>(b,c));
}

template <typename T>
T max4(T a, T b, T c, T d){
    return max<T>(max<T>(a,d),max<T>(b,c));
}


void adv_tokenizer(string s, char del) // Split string
{
    stringstream ss(s);
    string word;
    while (!ss.eof())
    {
        getline(ss, word, del);
        cout << word << endl;
    }
}

ll func(ll a,ll b){
    if(a%b == 0){
        return (a/b - 1);
    }
    else{
        return (a/b + func(b, a%b));
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a, b;
    cin >> a >> b;
    ll** arr;
    if(b > a){
        ll temp = a;
        a = b;
        b = temp;
    }
    arr = new ll* [a+1];
    for(int i = 1; i <=a; i++){
        arr[i] = new ll [b+1];
    }
    for(int i = 1; i <=b; i++){
        arr[i][i] = 0;
    }
    for(int i = 2; i<=a;i++){
        for(int j = 1; j < i; j++){
            arr[i][j] = LONG_LONG_MAX;
            for(int k = 1; k < j; k++){
                arr[i][j] = min<ll>(arr[i][j], 1+ arr[i][k]+ arr[i][j-k]);
            }
            for(int k = 1; k < i; k++){
                arr[i][j] = min<ll>(arr[i][j], 1+ arr[max<ll>(k,j)][min<ll>(k,j)]+arr[max<ll>(i-k,j)][min<ll>(i-k,j)]);
            }
        }
    }
    // for(int i = 1; i <= a; i++){
    //     for(int j = 1; j<=min<ll>(i,b); j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << arr[a][b] << endl;
}