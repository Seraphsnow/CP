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

bool comp(pll p1, pll p2)
{
    return p1.fi > p2.fi;
}

ll solve()
{
    ll n;
    cin >> n;
    if (n == 0)
    {
        return -1;
    }
    pll heights[n];
    ll arr1[n + 1], arr2[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> heights[i].fi;
        heights[i].se = i;
        arr1[i] = i;
        arr2[i] = i;
    }
    arr1[n] = n;
    arr2[n] = n;
    sort(heights, heights + n, comp);
    ll maxArea = heights[0].fi;
    arr1[heights[0].se + 1] = heights[0].se;
    arr2[heights[0].se] = heights[0].se + 1;
    for (int i = 1; i < n; i++)
    {
        ll area = (arr2[heights[i].se + 1] - arr1[heights[i].se]) * heights[i].fi;
        maxArea = max(maxArea, area);
        arr1[arr2[heights[i].se + 1]] = arr1[heights[i].se];
        arr2[arr1[heights[i].se]] = arr2[heights[i].se + 1];
    }
    return maxArea;
}

int main(int argc, char *argv[])
{

    while (true)
    {
        ll ans = solve();
        if (ans == -1)
        {
            break;
        }
        else{
            cout << ans << endl;
        }
    }
}