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

#define MOD 998244353

int main(int argc, char *argv[])
{
    ll n, a1, x, y, m, k;
    cin >> n >> a1 >> x >> y >> m >> k;
    ll arr[n + 1][2];
    arr[1][0] = a1;
    ll sum = a1, ai[n + 1];
    ai[1] = a1;
    for (int i = 1; i <= n; i++)
    {
        arr[i][0] = sum;
        if(i == n) break;
        ai[i + 1] = (ai[i] * x + y) % m;
        sum = (sum + ai[i + 1]) % MOD;
        // cout << arr[i][0] << endl;
        // cout << ai << endl;
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                if (i <= 1)
                {
                    arr[j][1] = a1;
                }
                else
                {
                    arr[j][1] = 0;
                }
                continue;
            }
            if (i == 1)
            {
                arr[j][1] = (arr[j - 1][1] + arr[j - 1][0] + ai[j]) % MOD;
            }

            else
            {
                arr[j][1] = (arr[j - 1][1] + arr[j - 1][0]) % MOD;
            }
        }
        for(int j = 1; j <=n; j++){
            arr[j][0] = arr[j][1];
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = ans ^ (i * arr[i][1]);
    }
    cout << ans << endl;
}