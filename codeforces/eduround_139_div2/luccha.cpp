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

vector<ll> primes(ll num)
{
    vector<ll> ans;
    if (num % 2 == 0)
        ans.pb(2);
    while (num % 2 == 0)
    {
        num = num / 2;
    }
    for (int i = 3; i < sqrt(num); i = i + 2)
    {
        if (num % i == 0)
        {
            ans.pb(i);
        }
        while (num % i == 0)
        {
            num = num / i;
        }
    }
    if (num != 1)
        ans.pb(num);
    return ans;
}

void solve(ll num, ll givennum)
{
    ll ans = num;
    if (num % 2 == 0)
    {
        if (givennum % 2 == 0)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            ans = 1;
        }
    }
    while (num % 2 == 0)
    {
        num = num / 2;
    }
    for (int i = 3; i < sqrt(num); i = i + 2)
    {
        if (num % i == 0)
        {
            if (givennum % i == 0)
            {
                cout << 0 << endl;
                return;
            }
            else
            {
                ll myans = i - givennum % i;
                if (myans < ans)
                {
                    ans = myans;
                }
            }
        }
        while (num % i == 0)
        {
            num = num / i;
        }
    }
    if (num != 1)
    {
        if (givennum % num == 0)
        {
            cout << 0 << endl;
            return;
        }
        else
        {
            ll myans = num - givennum % num;
            if (myans < ans)
            {
                ans = myans;
            }
        }
    }
    cout << ans << endl;
}

ll gcd(ll n, ll m)
{
    if (n % m == 0)
    {
        return m;
    }
    else
    {
        return gcd(m, n % m);
    }
}

int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll num1, num2;
        cin >> num1 >> num2;
        ll dif = abs(num1 - num2);
        if (dif == 1)
        {
            cout << -1 << endl;
            continue;
        }
        else if (dif == 0)
        {
            if (num1 == 1)
            {
                cout << 1 << endl;
                continue;
            }
            else
            {
                cout << 0 << endl;
                continue;
            }
        }
        solve(dif, max(num1,num2)%dif);
    }
}