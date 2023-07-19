#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;


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

bool comp(pll p1, pll p2){
    return ((p1.se*p2.fi - p1.fi*p2.se) < 0 )||(((p1.se*p2.fi - p1.fi*p2.se) == 0 ) && p1.se > p2.se); 
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    pll people[n];
    for(int i = 0; i < n; i++){
        cin >> people[i].fi;
        cin >> people[i].se;
        people[i].fi;
    }
    sort(people, people+n, comp);
    ld ans = LONG_LONG_MAX;
    for(int i = 0; i < n/2; i++){
        ans = min<ld>(ans, 1.0*(people[i].se+people[n-1-i].se)/(people[i].fi+people[n-1-i].fi + 20));
    }
    cout <<setprecision(6)<< ans << endl;
}