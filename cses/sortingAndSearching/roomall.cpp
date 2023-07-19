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

bool comp(ppll p1, ppll p2){
    return p1.fi.fi < p2.fi.fi || (p1.fi.fi == p2.fi.fi && p1.fi.se < p2.fi.se);
}

bool comp2(ppll p1, ppll p2){
    return p1.se.fi < p2.se.fi;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    ppll customers[n];
    for(int i = 0; i < n; i++){
        cin >> customers[i].fi.fi >> customers[i].fi.se;
        customers[i].se.fi = i;
    }
    sort(customers, customers+n, comp);
    set<pll> rooms;
    for(int i = 0; i < n; i++){
        auto it = rooms.upper_bound({-customers[i].fi.fi, n});
        if(it == rooms.end()){
            rooms.insert({-customers[i].fi.se,rooms.size()+1});
            customers[i].se.se = rooms.size();
        }
        else{
            rooms.erase(*it);
            rooms.insert({-customers[i].fi.se,(*it).se});
            customers[i].se.se = (*it).se;
        }

    }
    sort(customers, customers+n, comp2);
    cout << rooms.size() << endl;
    for(int i = 0; i < n; i++){
        cout << customers[i].se.se << " ";
    }
    cout << endl;
}