#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>
int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    multiset<ll> towers;
    ll num;
    cin >> num;
    towers.insert(num);
    for (int i = 1; i < n; i++)
    {
        cin >> num;
        auto it = towers.lower_bound(num + 1);
        if (it == towers.end())
        {
            towers.insert(num);
        }
        else
        {
            towers.erase(it);
            towers.insert(num);
        }
    }
    cout << towers.size() << endl;
}