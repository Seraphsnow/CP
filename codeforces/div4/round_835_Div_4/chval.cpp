#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

void solve()
{
    ll n;
    cin >> n;
    ll prev;
    cin >> prev;
    if (n == 1)
        cout << "YES\n";
    else if(n == 2){
        ll num;
        cin >> num;
        cout << "YES\n";
    }
    else
    {
        ll increasing = -1;
        bool ans=true;
        for (int i = 1; i < n; i++)
        {
            ll num;
            cin >> num;
            if(!ans) continue;
            if (increasing == -1)
            {
                if (num == prev)
                    continue;
                else if (num > prev)
                    increasing = 1;
                else
                    increasing = 0;
            }
            else
            {
                if (increasing)
                {
                    if (num >= prev)
                        continue;

                    else
                    {
                        ans = false;
                        continue;
                    }
                }
                else{
                    if(num <= prev)continue;
                    else{
                        increasing = 1;
                    }
                }
            }
            prev = num;
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}