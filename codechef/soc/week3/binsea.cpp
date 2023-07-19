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

ll g(ll k, ll *a, ll *b, ll n)
{
    ll ans = 0;
    deque<pll> max, min;
    for (int i = 0; i < n; i++)
    {
        ll maxin = i, minin = i;
        while (max.size() != 0)
        {
            pll p = max.back();
            if (p.fi > a[i])
            {
                break;
            }
            else
            {
                max.pop_back();
                maxin = p.se;
            }
        }
        max.push_back({a[i], maxin});
        while (min.size() != 0)
        {
            pll p = min.back();
            if (p.fi < b[i])
            {
                break;
            }
            else
            {
                min.pop_back();
                minin = p.se;
            }
        }
        min.push_back({b[i], minin});
        // cout << "hi1" << endl;
        // cout << i << endl;
        // cout << endl;
        // for (int j = 0; j < max.size(); j++)
        // {
        //     cout << j << " " << max[j].fi << " " << max[j].se << endl;
        // }
        // cout << endl;
        // for (int j = 0; j < min.size(); j++)
        // {
        //     cout << j << " " << min[j].fi << " " << min[j].se << endl;
        // }
        // cout << endl;
        while (max.size() != 0 && min.size() != 0)
        {
            pll currmax = max.front(), currmin = min.front();
            max.pop_front();
            min.pop_front();

            if (currmax.fi - currmin.fi > k)
            {
                if (max.size() != 0)
                {
                    if (max.front().se != currmax.se + 1)
                    {
                        max.push_front({currmax.fi, currmax.se + 1});
                    }
                }
                else
                {
                    if (currmax.se < i)
                    {
                        max.push_front({currmax.fi, currmax.se + 1});
                    }
                }
                if (min.size() != 0)
                {
                    if (min.front().se != currmin.se + 1)
                    {
                        min.push_front({currmin.fi, currmin.se + 1});
                    }
                }
                else
                {
                    if (currmin.se < i)
                    {
                        min.push_front({currmin.fi, currmin.se + 1});
                    }
                }
            }
            else
            {
                max.push_front(currmax);
                min.push_front(currmin);
                break;
            }
            // cout << "hi2" << endl;
            // for (int j = 0; j < max.size(); j++)
            // {
            //     cout << j << " " << max[j].fi << " " << max[j].se << endl;
            // }
            // cout << endl;
            // for (int j = 0; j < min.size(); j++)
            // {
            //     cout << j << " " << min[j].fi << " " << min[j].se << endl;
            // }
            // cout << endl;
        }
        // cout << "hi3" << endl;
        // cout << i << endl;
        // cout << endl;
        // for (int j = 0; j < max.size(); j++)
        // {
        //     cout << j << " " << max[j].fi << " " << max[j].se << endl;
        // }
        // cout << endl;
        // for (int j = 0; j < min.size(); j++)
        // {
        //     cout << j << " " << min[j].fi << " " << min[j].se << endl;
        // }
        // cout << endl;
        if (max.size() == 0)
        {
            continue;
        }
        else
        {
            ans += (i - max.front().se + 1);
        }
    }
    return ans;
}

void solve()
{
    ll n, u;
    cin >> n >> u;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll b[n];
    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }
    if(u > (n)*(n+1)/2){
        cout << -1 << endl;
        return;
    }
    ll max = 1;
    while (true)
    {
        //cout << max << endl;
        ll gk = g(max, a, b, n);
        // cout << gk << " " << max << " " << endl
        //      << endl;
        if (gk < u)
        {
            max = max * 2;
        }
        else
        {
            break;
        }
    }
    ll min = max / 2;
    while (true)
    {
        if (min == max)
        {
            //cout << min << endl;
            ll gk = g(min, a, b, n);
            //cout << gk << " " << min << " " << endl
            //     << endl;
            if (gk == u)
                cout << min << endl;
            else
                cout << -1 << endl;
            return;
        }
        else if (min > max)
        {
            cout << -1 << endl;
            return;
        }
        ll mid = (min + max) / 2;
        //cout << mid << endl;
        ll gk = g(mid, a, b, n);
        // cout << gk << " " << mid << " " << endl
        //      << endl;
        if (gk > u)
        {
            max = mid - 1;
        }
        else if (gk == u)
        {
            max = mid;
        }
        else
        {
            min = mid + 1;
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