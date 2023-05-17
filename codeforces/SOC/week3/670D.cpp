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

class cookie
{
public:
    ld has, needed;
    ld possible;
    cookie(){};
    void f()
    {
        possible = has / needed;
    }
};

bool comp(cookie p1, cookie p2)
{
    return p1.possible < p2.possible;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ld k;
    cin >> n >> k;
    cookie a[n]; // fi is needed and se is has
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].needed;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].has;
        a[i].f();
    }
    sort(a, a + n, comp);
    ll index = 1;
    ld ans = a[0].possible, totalpow = a[0].needed;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i].has << " " << a[i].needed << " " << a[i].possible << endl;
    // }
    while (k > 0)
    {
        if (index == n)
        {
            ans += k / totalpow;
            break;
        }
        ld diff = a[index].possible - a[index - 1].possible;
        //cout << index << " " << ans << " " << totalpow << " " << diff << " " << k << endl;
        if (k >= diff * totalpow)
        {
            k -= diff * totalpow;

            ans = a[index].possible;
            totalpow += a[index].needed;
            index++;
        }
        else
        {
            ans = ans + k / totalpow;
            break;
        }
    }
    cout << lround(floor(ans)) << endl;
}