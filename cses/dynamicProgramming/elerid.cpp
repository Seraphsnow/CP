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

class mysum
{
public:
    mysum() {}
    vector<ll> indices;
    ll sum;
};

vector<ll> weights;
vector<ll> vals;

bool func(ll ind, ll n, ll targetweight, ll min, ll check)
{
    // cout << ind << endl;
    if (ind == n)
    {
        vals.clear();
        return true;
    }
    else
    {
        if ((n - ind) <= (min - vals.size()))
        {
            return true;
        }
        for (int i = check; i < vals.size(); i++)
        {
            if (vals[i] + weights[ind] <= targetweight)
            {

                vals[i] = vals[i] + weights[ind];
                if (vals[i] + weights[n - 1] > targetweight && check == i)
                {
                    if (func(ind + 1, n, targetweight, min, check + 1))
                    {
                        return true;
                    }
                }
                else
                {
                    if (func(ind + 1, n, targetweight, min, check))
                    {
                        return true;
                    }
                }

                vals[i] = vals[i] - weights[ind];
            }
        }
        if (vals.size() < min)
        {
            vals.pb(weights[ind]);
            if (func(ind + 1, n, targetweight, min, check))
            {
                return true;
            }
            vals.pop_back();
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        ll num;
        cin >> num;
        weights.pb(num);
    }
    pll arr[1 << n];
    arr[0] = {1, 0};
    sort(weights.begin(), weights.end(), greater<ll>());
    for (int i = 1; i < 1 << n; i++)
    {
        arr[i] = {n + 1, 0};
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                ll sub = i ^ (1 << j);
                //cout << i << " " << j << " " << sub << endl;
                if (arr[sub].se + weights[j] <= x)
                {
                    if (arr[i].fi > arr[sub].fi)
                    {
                        arr[i] = arr[sub];
                        arr[i].se += weights[j];
                    }
                    else if (arr[i].fi == arr[sub].fi)
                    {
                        if (arr[i].se > arr[sub].se + weights[j])
                        {
                            arr[i].se = arr[sub].se + weights[j];
                        }
                    }
                    // arr[i] = min<pll>(arr[i], {arr[sub].fi, arr[sub].se+weights[j]});
                }
                else
                {
                    if (arr[i].fi > arr[sub].fi+1)
                    {
                        arr[i].fi = arr[sub].fi+1;
                        arr[i].se = weights[j];
                    }
                    else if (arr[i].fi == arr[sub].fi+1)
                    {
                        if (arr[i].se > weights[j])
                        {
                            arr[i].se = weights[j];
                        }
                    }
                    //arr[i] = min<pll>(arr[i], {arr[sub].fi + 1, weights[j]});
                }
            }
        }
        
    }
    // for(int i = 0; i < 1<<n; i++){
    //     cout << arr[i].fi << " " << arr[i].se << endl;
    // }

    cout << arr[(1 << n) - 1].fi << endl;
}