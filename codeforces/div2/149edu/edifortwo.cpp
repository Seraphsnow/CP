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

class myc
{
public:
    ll num;
    vector<ll> indices;
    myc() {}
};

bool comp1(pll p1, pll p2)
{
    return p1.fi < p2.fi || (p1.fi == p2.fi && p1.se < p2.se);
}

bool comp2(pll p1, pll p2)
{
    return p1.se < p2.se;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    pll arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].fi;
        arr[i].se = i;
    }

    sort(arr, arr + n, comp1);
    vector<myc *> nums;
    myc *elem;
    elem = new myc;
    elem->num = arr[0].fi;
    elem->indices.pb(arr[0].se);
    nums.pb(elem);
    for (int i = 1; i < n; i++)
    {
        if (arr[i].fi == nums.back()->num)
        {
            nums.back()->indices.pb(arr[i].se);
        }
        else
        {
            myc *elem;
            elem = new myc;
            elem->num = arr[i].fi;
            elem->indices.pb(arr[i].se);
            nums.pb(elem);
        }
    }

    vector<pll> useful;
    bool ez;
    myc* last;
    for (int i = 0; i < nums.size(); i++)
    {
        if (useful.size() < k)
        {
            for (int j = 0; j < nums[i]->indices.size(); j++)
            {
                useful.pb({nums[i]->num, nums[i]->indices[j]});
                
            }
        }
        else if (useful.size() == k)
        {
            ez = true;
            break;
        }
        else
        {
            ez = false;
            last = nums[i-1];
            break;
        }
    }

    if (ez)
    {

        ll sum = 0;
        //cout << useful.size() << endl;
        for (int i = 0; i < k; i++)
        {
            sum += useful[i].fi;
        }
        sort(useful.begin(), useful.end(), comp2);
        ll prefsum = 0;
        ll time = LONG_LONG_MAX;
        time = min(time, max(prefsum, sum - prefsum));
        for (int i = 0; i < k; i++)
        {
            prefsum += useful[i].fi;
            time = min(time, max(prefsum, sum - prefsum));
        }
        cout << time << endl;
    }
    else
    {
        ll sum = 0;
        //cout << useful.size() << endl;
        for (int i = 0; i < useful.size()-last->indices.size(); i++)
        {
            sum += useful[i].fi;
        }
        sort(useful.begin(), useful.end(), comp2);
        ll prefsum = 0;
        ll time = LONG_LONG_MAX;
        time = min(time, max(prefsum, sum - prefsum));
        ll bestindex= 0;
        for (int i = 0; i < useful.size(); i++)
        {
            if(useful[i].fi == last->num) continue;
            prefsum += useful[i].fi;
            if(max(prefsum, sum-prefsum) < time){
                time = max(prefsum, sum-prefsum);
                bestindex = useful[i].se;
            }
        }
        ll numleft = k + last->indices.size() - useful.size();

        cout << time << endl;
    }
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