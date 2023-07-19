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

void solve()
{
    ll q;
    cin >> q;
    ll hmin = 1, hmax = LONG_LONG_MAX;
    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ll a, b, n;
            cin >> a >> b >> n;
            if (n == 1)
            {
                ll currmin = 1;
                ll currmax = a;
                if (currmin > hmax || currmax < hmin)
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << 1 << " ";
                    hmin = max(currmin, hmin);
                    hmax = min(hmax, currmax);
                }
            }
            else
            {

                ll currmin = a * (n - 1) - b * (n - 2) + 1;
                ll currmax = a * (n) - b * (n - 1);
                if (currmin > hmax || currmax < hmin)
                {
                    cout << 0 << " ";
                }
                else
                {
                    cout << 1 << " ";
                    hmin = max(currmin, hmin);
                    hmax = min(hmax, currmax);
                }
            }
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            
            ll tmin = ceil((1.0 * (hmin - b)) / (1.0 * (a - b)));
            if(hmin <= a){
                tmin = 1;
            }
            ll tmax = ceil((1.0 * (hmax - b)) / (1.0 * (a - b)));
            if(hmax <= a){
                tmax = 1;
            }
            //cout << tmin << " " << tmax << endl;
            if (tmin == tmax)
            {
                cout << tmin << " ";
            }
            else
            {
                cout << -1 << " ";
            }
        }
        //cout << hmin << " " << hmax << endl;
    }
    cout << endl;
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