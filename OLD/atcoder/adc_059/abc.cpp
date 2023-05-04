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

void solve(string s)
{
    vector<char> distinct;
    distinct.pb(s[0]);
    for (int i = 0; i < s.size(); i++)
    {
        if (distinct.back() != s[i])
        {
            distinct.pb(s[i]);
        }
    }
    int aans = 0, bans = 0, cans = 0;
    for (int i = 0; i < distinct.size(); i++)
    {
        if (distinct[i] == 'A')
            continue;
        else
        {
            if (i + 1 == distinct.size())
            {
                aans++;
                break;
            }
            else if (distinct[i + 1] == 'A')
            {
                if (i + 2 == distinct.size() || distinct[i+2] != distinct[i])
                {
                    aans++;
                    i++;
                }
                

            }
            else if (i + 2 == distinct.size())
            {
                aans += 2;
                break;
            }
            else if (distinct[i + 2] == 'A')
            {
                aans += 2;
                i += 2;
            }
            else
            {
                aans += 1;
                i += 1;
            }
        }
    }
    for (int i = 0; i < distinct.size(); i++)
    {
        if (distinct[i] == 'B')
            continue;
        else
        {
            if (i + 1 == distinct.size())
            {
                bans++;
                break;
            }
            else if (distinct[i + 1] == 'B')
            {
                bans++;
                i++;
            }
            else if (i + 2 == distinct.size())
            {
                bans += 2;
                break;
            }
            else if (distinct[i + 2] == 'B')
            {
                bans += 2;
                i += 2;
            }
            else
            {
                bans += 1;
                i += 1;
            }
        }
    }
    for (int i = 0; i < distinct.size(); i++)
    {
        if (distinct[i] == 'C')
            continue;
        else
        {
            if (i + 1 == distinct.size())
            {
                cans++;
                break;
            }
            else if (distinct[i + 1] == 'C')
            {
                cans++;
                i++;
            }
            else if (i + 2 == distinct.size())
            {
                cans += 2;
                break;
            }
            else if (distinct[i + 2] == 'C')
            {
                cans += 2;
                i += 2;
            }
            else
            {
                cans += 1;
                i += 1;
            }
        }
    }
    cout << min(aans, min(bans, cans)) << endl;
}

int main(int argc, char *argv[])
{
    ll N, Q;
    string S;
    cin >> N >> Q >> S;
    while (Q--)
    {
        ll l, r;
        cin >> l >> r;
        solve(S.substr(l - 1, r - l + 1));
    }
}