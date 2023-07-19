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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> primes;
    ll num = n;
    ll count = 0;
    while (num % 2 == 0)
    {
        num = num / 2;
        count++;
    }
    if (count > 0)
    {
        primes.pb(2);
    }

    for (ll i = 3; i <= sqrt(num); i += 2)
    {
        ll count = 0;
        while (num % i == 0)
        {
            num = num / i;
            count++;
        }
        if (count > 0)
        {
            primes.pb(i);
        }
    }

    if (num > 2)
    {

        primes.pb(num);
    }
    bool arr[n];
    for(int i = 1; i <n; i++){
        arr[i] = true;
    }
    for(int i = 0; i < primes.size(); i++){
        ll currprime = primes[i];
        ll currnum = currprime;
        while(currnum <=n-1){
            arr[currnum] = false;
            currnum+=currprime;
        }
    }
    ll ans = 1;
    ll total = 0;
    for(int i = 1; i < n; i++){
        if(arr[i]){
            ans = (ans * i) % n;
            total+=1;
        }
    }
    if(ans == 1){
        cout << total << endl;
        for(int i = 1; i < n; i++){
            if(arr[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    else{
        cout << total-1 << endl;
        for(int i = 1; i < n; i++){
            if(arr[i] && i != ans){
                cout << i << " ";
            }
        }
        cout << endl;
    }
}