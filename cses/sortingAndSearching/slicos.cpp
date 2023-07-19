#include <bits/stdc++.h>
using namespace std;

// For policy data structures
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>

typedef tree<pll, null_type, less<pll>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    indexed_set s1;
    for (int i = 0; i < k; i++)
    {
        s1.insert({arr[i], i});
    }

    ll cost = 0;
    ll mid = (k - 1) / 2;
    for (int i = 0; i < k; i++)
    {
        ll median = (*s1.find_by_order(mid)).fi;
        if (i <= mid)
        {
            cost += median - (*s1.find_by_order(i)).fi;
        }
        else
        {
            cost += (*s1.find_by_order(i)).fi - median;
        }
    }
    cout << cost << " ";
    for (int i = k; i < n; i++)
    {
        pll origmid = (*s1.find_by_order(mid));
        s1.insert({arr[i], i});
        s1.erase({arr[i - k], i - k});
        pll newmid = (*s1.find_by_order(mid));
        if (newmid == origmid)
        {
            if (arr[i] < origmid.fi)
            {
                cost = cost - arr[i] + arr[i - k];
            }
            else
            {
                cost = cost + arr[i] - arr[i - k];
            }
        }
        else
        {
            if (arr[i - k] > origmid.fi)
            {
                if (k % 2 == 1)
                {
                    cost = cost - arr[i - k] + origmid.fi - arr[i] + newmid.fi;
                }
                else
                {
                    cost = cost + 2 * origmid.fi - arr[i - k] - arr[i];
                }
            }
            else if (arr[i - k] == origmid.fi && i-k == origmid.se)
            {
                if (arr[i] >= arr[i - k])
                {
                    if (k % 2 == 1)
                    {
                        cost = cost + arr[i] - newmid.fi;
                    }
                    else
                    {
                        cost = cost + origmid.fi - 2 * newmid.fi + arr[i];
                    }
                }
                else
                {
                    if (k % 2 == 1)
                    {
                        cost = cost - arr[i] + newmid.fi;
                    }
                    else
                    {
                        cost = cost + origmid.fi - arr[i];
                    }
                }
            }
            else
            {
                if (k % 2 == 1)
                {
                    cost = cost + arr[i - k] - origmid.fi + arr[i] - newmid.fi;
                }
                else
                {
                    cost = cost + arr[i - k] + arr[i] -2*newmid.fi;
                }
            }
        }
        cout << cost << " ";
    }
    cout << endl;
}