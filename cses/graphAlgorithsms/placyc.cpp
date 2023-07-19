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

ll mypow(ll a, ll b, ll m)
{
    ll ans = 1, pow = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            ans = (ans * pow) % m;
        }
        pow = (pow * pow) % m;
        b = b / 2;
    }
    return ans;
}

ll modInverse(ll A, ll M)
{
    ll m0 = M;
    ll y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        ll q = A / M;
        ll t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q;
    cin >> n >> q;
    ll tel[n];
    for (int i = 0; i < n; i++)
    {
        ll next;
        cin >> next;
        tel[i] = next - 1;
    }

    ll boss[n];
    ll ind[n];
    ll visited[n];
    vector<pair<vector<ll>, pair<bool, pll>>> nodes;
    for (int i = 0; i < n; i++)
    {
        boss[i] = -1;
        visited[i] = 0;
    }

    ll currind = 0;
    ll concompnum = 0;
    while (currind < n)
    {

        if (visited[currind])
        {
            currind++;
            continue;
        }
        vector<ll> concomp;
        ll index = 0;
        concomp.pb(currind);
        visited[currind] = 1;
        ind[currind] = index;
        ll currnode = currind;
        boss[currnode] = concompnum;
        ll cyclestart;
        
        while (true)
        {
            ll child = tel[currnode];
            concomp.pb(child);
            index++;
            if (visited[child])
            {
                cyclestart = child;
                break;
            }
            else
            {
                boss[child] = concompnum;
                ind[child] = index;
                visited[child] = 1;
                currnode = child;
            }
        }
        ll find = -1, size;
        for (int i = 0; i < concomp.size() - 1; i++)
        {
            if (concomp[i] == cyclestart)
            {
                find = i;
                size = concomp.size() - i - 1;
            }
        }
        if (find == -1)
        {
            concompnum++;
            nodes.pb({concomp, {0, {find, size}}});
        }
        else
        {
            concompnum++;
            nodes.pb({concomp, {1, {find, size}}});
        }
    }

    for (auto u : nodes)
    {
        for (auto v : u.fi)
        {
            cout << v << " ";
        }
        cout << endl;
        cout << u.se.fi << endl;
        cout << u.se.se.fi << endl;
        cout << u.se.se.se << endl;
    }
    for(int i = 0; i < n; i++){
        cout << boss[i] << endl;
    }
    cout << endl;
    // cout << "HI" << endl;
    for (int i = 0; i < q; i++)
    {
        ll x, k;
        cin >> x >> k;
        x--;
        //cout << boss[x] << endl;
        vector<ll> concomp = nodes[boss[x]].fi;
        ll cycinside = nodes[boss[x]].se.fi;

        ll cycstart = nodes[boss[x]].se.se.fi;
        ll cycsize = nodes[boss[x]].se.se.se;
        // cout << x << endl
        //      << k << endl;
        // for (auto u : concomp)
        // {
        //     cout << u << " ";
        // }
        // cout << endl;
        // cout << cycstart << endl;
        // cout << cycsize << endl;
        // cout << cycinside << endl;
        while(!cycinside){
            
        }

        if (cycinside)
        {

            if (ind[x] >= cycstart)
            {

                // cout << "HI" << endl;
                k = k % cycsize;
                ll newind = ind[x] + k;
                // cout << ind[x] << " " << k << endl;
                // cout << newind << endl;
                if (newind >= concomp.size())
                {
                    newind -= cycsize;
                }
                //cout << newind << endl;
                cout << concomp[newind] + 1 << endl;
            }
            else
            {
                if (k > cycstart - ind[x])
                {
                    k = k - (cycstart - ind[x]);
                    k = k % cycsize;
                    ll newind = cycstart + k;
                    if (newind >= concomp.size())
                    {
                        newind -= cycsize;
                    }
                    cout << concomp[newind] + 1 << endl;
                }
                else
                {
                    ll newind = ind[x] + k;
                    cout << concomp[newind] + 1 << endl;
                }
            }
        }
        else
        {
            if (k < concomp.size())
            {
                cout << concomp[k] + 1 << endl;
            }
            else
            {
                k -= concomp.size();
                k++;
                ll x = concomp.back();
                vector<ll> concomp = nodes[ind[x]].fi;
                ll cycinside = nodes[ind[x]].se.fi;

                ll cycstart = nodes[ind[x]].se.se.fi;
                ll cycsize = nodes[ind[x]].se.se.se;
                if (ind[x] >= cycstart)
                {
                    k = k % cycsize;
                    ll newind = ind[x] + k;
                    if (newind >= concomp.size())
                    {
                        newind -= cycsize;
                    }
                    cout << concomp[newind] + 1 << endl;
                }
                else
                {
                    if (k > cycstart - ind[x])
                    {
                        k = k - (cycstart - ind[x]);
                        k = k % cycsize;
                        ll newind = cycstart + k;
                        if (newind >= concomp.size())
                        {
                            newind -= cycsize;
                        }
                        cout << concomp[newind] + 1 << endl;
                    }
                    else
                    {
                        ll newind = ind[x] + k;
                        cout << concomp[newind] + 1 << endl;
                    }
                }
            }
        }
       // break;
    }
}