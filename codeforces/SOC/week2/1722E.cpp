#include <bits/stdc++.h>
#include <cstdint>

using namespace std;

#define ll long long int
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
ll **recs;
ll **lessthanequal;
    
void setup()
{
    recs = new ll *[1001];
    for (int i = 0; i <= 1000; i++)
    {
        recs[i] = new ll[1001];
    }
    lessthanequal = new ll *[1001];
    for (int i = 0; i <= 1000; i++)
    {
        lessthanequal[i] = new ll[1001];
    }
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            recs[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll h, w;
        cin >> h >> w;
        recs[h][w]++;
    }
    for (int i = 0; i <= 1000; i++)
    {
        lessthanequal[i][0] = 0;
        lessthanequal[0][i] = 0;
    }

    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            lessthanequal[i][j] = i * j * recs[i][j] + lessthanequal[i - 1][j] + lessthanequal[i][j - 1] - lessthanequal[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        ll hs, ws, hb, wb;
        cin >> hs >> ws >> hb >> wb;
        cout << lessthanequal[hb - 1][wb - 1] - lessthanequal[hs][wb - 1] - lessthanequal[hb - 1][ws] + lessthanequal[hs][ws] << endl;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    setup();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}