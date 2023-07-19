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

bool comp(pll p1, pll p2)
{
    return p1.fi < p2.fi || ((p1.fi == p2.fi) && (p1.se < p2.se));
}

class mydata
{
public:
    ll num;
    vector<ll> indices;
    mydata()
    {
    }
};

void solve()
{
    ll n;
    cin >> n;
    ll b[n];
    pll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a, a + n, comp);
    vector<mydata *> un;
    mydata *elem;
    elem = new mydata;
    elem->num = a[0].fi;
    elem->indices.pb(a[0].se);
    un.pb(elem);
    for (int i = 1; i < n; i++)
    {
        if (a[i].fi == un.back()->num)
        {
            un.back()->indices.pb(a[i].se);
        }
        else
        {
            mydata *elem;
            elem = new mydata;
            elem->num = a[i].fi;
            elem->indices.pb(a[i].se);
            un.pb(elem);
        }
    }
    ll mex = 0;
    ll index = un.size();
    for (int i = 0; i < un.size(); i++)
    {
        if (un[i]->num < 0)
        {
            continue;
        }
        else
        {
            if (un[i]->num == mex)
            {
                mex++;
            }
            else
            {
                index = i;
                break;
            }
        }
    }
    if (mex == n)
    {
        cout << "NO\n";
        return;
    }
    if (mex == 0)
    {
        cout << "YES\n";
        return;
    }
    if (index == un.size())
    {
        cout << "YES\n";
        return;
    }
    ll find = un[index]->num;

    if (find > mex + 1)
    {
        cout << "YES\n";
        return;
    }

    ll minindex, maxindex;
    for (int i = 0; i < un.size(); i++)
    {
        if (un[i]->num == find)
        {
            minindex = un[i]->indices[0];
            maxindex = un[i]->indices.back();
            break;
        }
    }
    for (int i = 0; i < un.size(); i++)
    {
        if (un[i]->num < 0)
        {
            continue;
        }
        else if (un[i]->num < find)
        {
            bool poss = false;
            for (int j = 0; j < un[i]->indices.size(); j++)
            {
                if (un[i]->indices[j] < minindex || un[i]->indices[j] > maxindex)
                {
                    poss = true;
                    break;
                }
            }
            if (!poss)
            {
                cout << "No\n";
                return;
            }
        }
        else
        {
            break;
        }
    }
    cout << "YES\n";
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