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
#define pld pair<ld, ld>

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

ld speed;

bool comp(pld p1, pld p2)
{
    return (p1.se * p1.fi + p1.se*p2.fi + p2.fi*p2.fi*speed < p2.se*p1.fi + p2.se*p2.fi + p1.fi*p1.fi*speed);
}

bool poss(ld speed , pld* people, ll n){
    ld x[n];
    for(int i = 0; i < n; i++){
        x[i] = people[i].se - speed*people[i].fi;
    }
    
    sort(x, x+n);
    for(int i = 0; i < n/2; i++){
        if((x[i] + x[n-1-i]) < 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    pld people[n];
    for(int i = 0; i < n; i++){
        cin >> people[i].fi;
        cin >> people[i].se;
        people[i].fi+=10;
    }
    ld min = 5.0/11;
    ld max = 5.0/3;

    while(true){
        //  cout << max << " " << min << endl;
        if(max - min < 0.0000001){
            cout << max << endl;
            break;
        }
        ld mid = (max+min)/2;
        speed = mid;
        if(poss(mid, people, n)){
            min = mid;
        }
        else{
            max = mid;
        }
    }
}