#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// #define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

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
T min3(T a, T b, T c)
{
    return min<T>(a, min<T>(b, c));
}

template <typename T>
T min4(T a, T b, T c, T d)
{
    return min<T>(min<T>(a, d), min<T>(b, c));
}

template <typename T>
T max3(T a, T b, T c)
{
    return max<T>(a, max<T>(b, c));
}

template <typename T>
T max4(T a, T b, T c, T d)
{
    return max<T>(max<T>(a, d), max<T>(b, c));
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

bool poss(ll** arr,ll *a, ll n, ll sum)
{
    if (sum < 0 || n<=0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if(arr[n-1][sum-1] != -1){
        return arr[n-1][sum-1];
    }
    if(poss(arr,a, n - 1, sum - a[n-1])){
        arr[n-1][sum-1] = 1;
        return 1;
    }
    else if(poss(arr,a, n - 1, sum)){
        arr[n-1][sum-1] = 1;
        return 1;
    }
    else{
        arr[n-1][sum-1] = 0;
        return 0;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[n];
    ll minInd = -1;
    ll min = 10000;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < min && a[i] % 2 == 1)
        {
            min = a[i];
            minInd = i + 1;
        }
        sum += a[i];
    }
    if (sum % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    while (minInd == -1)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = a[i] / 2;
            if (a[i] < min && a[i] % 2 == 1)
            {
                min = a[i];
                minInd = i + 1;
            }
        }
        sum = sum / 2;
        if (sum % 2 == 1)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    sort(a , a+n);
    ll** arr;
    arr = new ll* [n];
    for(int i = 0; i < n; i++){
        arr[i] = new ll [sum/2];
        for(int j = 0; j < sum/2; j++){
            arr[i][j] = -1;
        }
    }
    //cout << sum << endl;
    if (poss(arr, a, n, sum / 2))
    {
        cout << 1 << endl;
        cout << minInd << endl;
        ;
    }
    else
    {
        cout << 0 << endl;
    }
}