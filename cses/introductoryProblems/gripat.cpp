#include <bits/stdc++.h>
using namespace std;

// For policy data structures
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;

// #define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

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

template <typename T>
T min3(T a, T b, T c)
{
    return min<T>(a, min<T>(b, c));
}

template <typename T>
T min4(T a, T b, T c, T d)
{
    return min<T>(min<T>(a, d), min<T>(b, c));
}

template <typename T>
T max3(T a, T b, T c)
{
    return max<T>(a, max<T>(b, c));
}

template <typename T>
T max4(T a, T b, T c, T d)
{
    return max<T>(max<T>(a, d), max<T>(b, c));
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

string s;

void search(ll moves, ll &count, bool **arr, ll x, ll y)
{
    if (moves == 48)
    {
        if (x == 6 && y == 0)
            count++;
    }
    else
    {
        if (x == 0)
        {
            if (y == 0)
            {
                if (!arr[x + 1][y] && (s[moves] == '?' || s[moves] == 'D'))
                {
                    arr[x + 1][y] = 1;
                    search(moves + 1, count, arr, x + 1, y);
                    arr[x + 1][y] = 0;
                }
                if (!arr[x][y + 1] && (s[moves] == '?' || s[moves] == 'R'))
                {
                    arr[x][y + 1] = 1;
                    search(moves + 1, count, arr, x, y + 1);
                    arr[x][y + 1] = 0;
                }
            }
            else if (y == 6)
            {
                if (!arr[x + 1][y] && (s[moves] == '?' || s[moves] == 'D'))
                {
                    arr[x + 1][y] = 1;
                    search(moves + 1, count, arr, x + 1, y);
                    arr[x + 1][y] = 0;
                }
            }
            else
            {
                if (!arr[x + 1][y] && (s[moves] == '?' || s[moves] == 'D'))
                {
                    arr[x + 1][y] = 1;
                    search(moves + 1, count, arr, x + 1, y);
                    arr[x + 1][y] = 0;
                }
                if (!arr[x][y + 1] && (s[moves] == '?' || s[moves] == 'R') && arr[x][y - 1])
                {
                    arr[x][y + 1] = 1;
                    search(moves + 1, count, arr, x, y + 1);
                    arr[x][y + 1] = 0;
                }
            }
        }
        else if (x == 6)
        {
            if (y == 0)
            {
            }
            else if (y == 6)
            {
                if (!arr[x][y - 1] && (s[moves] == '?' || s[moves] == 'L'))
                {
                    arr[x][y - 1] = 1;
                    search(moves + 1, count, arr, x, y - 1);
                    arr[x][y - 1] = 0;
                }
            }
            else
            {
                if (!arr[x - 1][y] && (s[moves] == '?' || s[moves] == 'U'))
                {
                    arr[x - 1][y] = 1;
                    search(moves + 1, count, arr, x - 1, y);
                    arr[x - 1][y] = 0;
                }
                if (!arr[x][y - 1] && (s[moves] == '?' || s[moves] == 'L') && arr[x][y + 1])
                {
                    arr[x][y - 1] = 1;
                    search(moves + 1, count, arr, x, y - 1);
                    arr[x][y - 1] = 0;
                }
            }
        }
        else
        {
            if (y == 0)
            {
                if (!arr[x + 1][y] && (s[moves] == '?' || s[moves] == 'D') && arr[x - 1][y])
                {
                    arr[x + 1][y] = 1;
                    search(moves + 1, count, arr, x + 1, y);
                    arr[x + 1][y] = 0;
                }
                if (!arr[x][y + 1] && (s[moves] == '?' || s[moves] == 'R'))
                {
                    arr[x][y + 1] = 1;
                    search(moves + 1, count, arr, x, y + 1);
                    arr[x][y + 1] = 0;
                }
            }
            else if (y == 6)
            {
                if (!arr[x + 1][y] && (s[moves] == '?' || s[moves] == 'D') && arr[x - 1][y])
                {
                    arr[x + 1][y] = 1;
                    search(moves + 1, count,arr, x + 1, y);
                    arr[x + 1][y] = 0;
                }
                if (!arr[x][y - 1] && (s[moves] == '?' || s[moves] == 'L'))
                {
                    arr[x][y - 1] = 1;
                    search(moves + 1, count, arr, x, y - 1);
                    arr[x][y - 1] = 0;
                }
            }
            else
            {
                if (arr[x - 1][y] || (!arr[x - 1][y] && (!arr[x][y - 1] || !arr[x][y + 1])))
                {
                    if (!arr[x + 1][y] && (s[moves] == '?' || s[moves] == 'D'))
                    {
                        arr[x + 1][y] = 1;
                        search(moves + 1, count, arr, x + 1, y);
                        arr[x + 1][y] = 0;
                    }
                }
                if (arr[x + 1][y] || (!arr[x + 1][y] && (!arr[x][y - 1] || !arr[x][y + 1])))
                {
                    if (!arr[x - 1][y] && (s[moves] == '?' || s[moves] == 'U'))
                    {
                        arr[x - 1][y] = 1;
                        search(moves + 1, count, arr, x - 1, y);
                        arr[x - 1][y] = 0;
                    }
                }
                if (arr[x][y - 1] || (!arr[x][y - 1] && (!arr[x + 1][y] || !arr[x - 1][y])))
                {
                    if (!arr[x][y + 1] && (s[moves] == '?' || s[moves] == 'R'))
                    {
                        arr[x][y + 1] = 1;
                        search(moves + 1, count, arr, x, y + 1);
                        arr[x][y + 1] = 0;
                    }
                }
                if (arr[x][y + 1] || (!arr[x][y + 1] && (!arr[x + 1][y] || !arr[x - 1][y])))
                {
                    if (!arr[x][y - 1] && (s[moves] == '?' || s[moves] == 'L'))
                    {
                        arr[x][y - 1] = 1;
                        search(moves + 1, count, arr, x, y - 1);
                        arr[x][y - 1] = 0;
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    ll count = 0;
    bool **arr;
    arr = new bool *[7];
    for (int i = 0; i < 7; i++)
    {
        arr[i] = new bool[7];
        for (int j = 0; j < 7; j++)
        {
            arr[i][j] = 0;
        }
    }
    arr[0][0] = 1;
    search(0, count, arr, 0, 0);
    cout << count << endl;
}