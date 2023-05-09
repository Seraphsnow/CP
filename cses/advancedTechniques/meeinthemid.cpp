#include <bits/stdc++.h>
using namespace std;

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

vector<ll> s1, s2;

ll solve(ll *arr, ll left, ll x, ll n)
{
    if (x == 0)
    {
        return 1;
    }
    if (x < 0)
    {
        return 0;
    }
    if (left == 0)
    {
        return 0;
    }
    ll ans = solve(arr, left - 1, x - arr[n - left], n) + solve(arr, left - 1, x, n);
    return ans;
}

void solve2(ll *arr, ll left, ll n, ll ans)
{
    if (left == 0)
    {
        s1.push_back(ans);
        return;
    }
    else
    {
        solve2(arr, left - 1, n, ans);
        solve2(arr, left - 1, n, ans + arr[n - left]);
    }
}

void solve3(ll *arr, ll left, ll n, ll ans)
{
    if (left == 0)
    {
        s2.push_back(ans);
        return;
    }
    else
    {
        solve3(arr, left - 1, n, ans);
        solve3(arr, left - 1, n, ans + arr[n - left]);
    }
}

int main(int argc, char *argv[])
{
    ll n, x;
    cin >> n >> x;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve2(arr, n / 2, n, 0);
    solve3(arr, (n + 1) / 2, (n + 1) / 2, 0);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    vector<pll> p1, p2;
    for (int i = 0; i < s1.size(); i++)
    {
        if (p1.size() == 0)
        {
            p1.push_back({s1[i], 1});
        }
        else
        {
            if (p1.back().fi == s1[i])
            {
                p1.back().se += 1;
            }
            else
            {
                p1.push_back({s1[i], 1});
            }
        }
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (p2.size() == 0)
        {
            p2.push_back({s2[i], 1});
        }
        else
        {
            if (p2.back().fi == s2[i])
            {
                p2.back().se += 1;
            }
            else
            {
                p2.push_back({s2[i], 1});
            }
        }
    }
    ll i1 = 0, i2 = p2.size() - 1, ans = 0;
    while (true)
    {
        if(i1 == p1.size() || i2 == -1) break;
        if(p1[i1].fi+ p2[i2].fi == x){
            ans+= p1[i1].se*p2[i2].se;
            i1++;
            i2--;
        }
        else if(p1[i1].fi+ p2[i2].fi < x){
            i1++;
        }
        else{
            i2--;
        }
    }

    cout << ans << endl;
    // printVector<ll>(s1);
    // printVector<ll>(s2);

    // cout << solve(arr, n, x, n) << endl;
}