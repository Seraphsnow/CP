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

bool possible(ll **arr, ll n, ll m, ll size)
{
    ll **mya;
    mya = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        mya[i] = new ll[m];
    }
    if (arr[n - 1][m - 1] >= size)
    {
        mya[n - 1][m - 1] = 1; // first indicates front and second indicates bottom
    }
    else
    {
        mya[n - 1][m - 1] = 0;
    }
    if (mya[n - 1][m - 1] >= size)
    {
        return true;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i][m - 1] >= size)
        {
            mya[i][m - 1] = 1;
        }
        else
        {
            mya[i][m - 1] = 0;
        }
        if (mya[i][m - 1] >= size)
        {
            //cout << size << " " << i << " " << m-1 << endl;
            return true;
        }
    }
    for (int i = m - 2; i >= 0; i--)
    {
        if (arr[n - 1][i] >= size)
        {
            mya[n - 1][i] = 1;
        }
        else
        {
            mya[n - 1][i] = 0;
        }
        if (mya[n - 1][i] >= size)
        {
            //cout <<size << " "<< n - 1 << " " << i << endl;
            return true;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = m - 2; j >= 0; j--)
        {
            if (arr[i][j] >= size)
            {
                mya[i][j] = min3<ll>(mya[i][j+1], mya[i+1][j], mya[i+1][j+1]) + 1;
            }
            else
            {
                mya[i][j] = 0;
            }
            if (mya[i][j] >= size)
            {
            //    cout << size << " " << i << " " << j << endl;
            
                return true;
            }
        }
    }
    
    return false;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll **arr;
    arr = new ll *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new ll[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll min = 1, max = n;
    while (true)
    {
        if (min == max)
        {
            cout << min << endl;
            return;
        }
        ll mid = (min + max + 1) / 2;
        bool poss = possible(arr, n, m, mid);
        if (poss)
        {
            min = mid;
        }
        else
        {
            max = mid - 1;
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}