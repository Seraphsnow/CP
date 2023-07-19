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
    ll n, m;
    cin >> n >> m;
    if (m == 1)
    {
        if (n % 2 == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
        return 0;
    }
    if (n % 2 == 1 && m % 2 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    ll **arr;
    arr = new ll *[m];

    ll tot = mypow(2, n, 10000);

    for (int i = 0; i < m; i++)
    {
        arr[i] = new ll[tot];
    }
    vector<ll> inds[tot];
    for (int i = 0; i < tot; i++)
    {
        ll count = 0;
        ll num = i;
        while (num > 0)
        {
            if (num % 2 == 1)
            {
                inds[i].pb(count);
            }
            num = num / 2;
            count++;
        }
    }
    vector<ll> nonzers[tot];
    for (int i = 0; i < tot; i++)
    {
        for (int j = i; j < tot; j++)
        {
            ll bia = i & j;
            if (bia == 0)
            {
                nonzers[i].pb(j);
                if (i != j)
                {
                    nonzers[j].pb(i);
                }
            }
        }
    }
    bool poss[tot];
    for (int i = 0; i < tot; i++)
    {
        ll num = i;
        ll count = 0;
        vector<ll> ones;
        ones.pb(-1);
        poss[i] = true;

        while (num > 0)
        {
            if (num % 2 == 1)
            {
                ones.pb(count);
            }
            num = num / 2;
            count++;
        }
        ones.pb(n);
        for (int j = 1; j < ones.size(); j++)
        {
            if ((ones[j] - ones[j - 1]) % 2 == 0)
            {
                poss[i] = false;
                break;
            }
        }
    }

    vector<ll> **gapsjk;
    gapsjk = new vector<ll> *[tot];
    for (int i = 0; i < tot; i++)
    {
        gapsjk[i] = new vector<ll>[tot];
        for (int l = 0; l < nonzers[i].size(); l++)
        {
            ll j = i;
            ll k = nonzers[i][l];

            ll currj = 0, currk = 0;
            ll prev = -1;
            while (true)
            {
                if (currj == inds[j].size() && currk == inds[k].size())
                {
                    break;
                }
                if (currj == inds[j].size())
                {
                    gapsjk[j][k].pb(inds[k][currk] - prev - 1);
                    prev = inds[k][currk];
                    currk++;
                }
                else if (currk == inds[k].size())
                {
                    gapsjk[j][k].pb(inds[j][currj] - prev - 1);
                    prev = inds[j][currj];
                    currj++;
                }
                else
                {
                    if (inds[j][currj] < inds[k][currk])
                    {
                        gapsjk[j][k].pb(inds[j][currj] - prev - 1);
                        prev = inds[j][currj];
                        currj++;
                    }
                    else
                    {
                        gapsjk[j][k].pb(inds[k][currk] - prev - 1);
                        prev = inds[k][currk];
                        currk++;
                    }
                }
            }
            // ll currans = 1;
            if (inds[j].size() == 0 && inds[k].size() == 0)
            {
                gapsjk[j][k].pb(n);
            }
            else
            {
                if (inds[j].size() == 0)
                {
                    gapsjk[j][k].pb(n - 1 - inds[k][inds[k].size() - 1]);
                }
                else if (inds[k].size() == 0)
                {
                    gapsjk[j][k].pb(n - 1 - inds[j][inds[j].size() - 1]);
                }
                else
                {
                    if (inds[k][inds[k].size() - 1] > inds[j][inds[j].size() - 1])
                    {
                        gapsjk[j][k].pb(n - 1 - inds[k][inds[k].size() - 1]);
                    }
                    else
                    {
                        gapsjk[j][k].pb(n - 1 - inds[j][inds[j].size() - 1]);
                    }
                }
            }
        }
    }
    if (n % 2 == 0)
    {
        arr[0][0] = 1;
    }
    else
    {
        arr[0][0] = 0;
    }
    for (int i = 1; i < tot; i++)
    {
        ll currans = 1;
        if ((inds[i][0]) % 2 == 1)
        {
            // currans = currans * mypow(2, (inds[i][0]) / 2, LONG_LONG_MAX);
            currans = 0;
            arr[0][i] = 0;
            continue;
        }
        for (int j = 1; j < inds[i].size(); j++)
        {
            if ((inds[i][j] - inds[i][j - 1] - 1) % 2 == 0)
            {
                // currans = currans * mypow(2, (inds[i][j] - inds[i][j - 1] - 1) / 2, LONG_LONG_MAX);
            }
            else
            {
                currans = 0;
                break;
            }
        }

        if ((n - inds[i][inds[i].size() - 1] - 1) % 2 == 0)
        {
            // currans = currans * mypow(2, (n - inds[i][inds[i].size() - 1] - 1) / 2, LONG_LONG_MAX);
        }
        else
        {
            currans = 0;
        }
        arr[0][i] = currans;
    }

    for (int i = 1; i < m - 1; i++)
    {
        // cout << i << endl;
        for (int j = 0; j < tot; j++)
        {
            vector<ll> indsj = inds[j];
            arr[i][j] = 0;
            for (int l = 0; l < nonzers[j].size(); l++)
            {
                ll k = nonzers[j][l];
                // vector<ll> indsk = inds[k];
                // cout << "HI!" << endl;
                // cout << j << " " << k << " " << bia << endl;
                // cout << "BYE " << endl;
                // vector<ll> gaps;
                // ll prev = -1;
                // ll currj = 0, currk = 0;

                // while (true)
                // {
                //     if (currj == indsj.size() && currk == indsk.size())
                //     {
                //         break;
                //     }
                //     if (currj == indsj.size())
                //     {
                //         gaps.pb(indsk[currk] - prev - 1);
                //         prev = indsk[currk];
                //         currk++;
                //     }
                //     else if (currk == indsk.size())
                //     {
                //         gaps.pb(indsj[currj] - prev - 1);
                //         prev = indsj[currj];
                //         currj++;
                //     }
                //     else
                //     {
                //         if (indsj[currj] < indsk[currk])
                //         {
                //             gaps.pb(indsj[currj] - prev - 1);
                //             prev = indsj[currj];
                //             currj++;
                //         }
                //         else
                //         {
                //             gaps.pb(indsk[currk] - prev - 1);
                //             prev = indsk[currk];
                //             currk++;
                //         }
                //     }
                // }
                ll currans = 1;
                // if (indsj.size() == 0 && indsk.size() == 0)
                // {
                //     gaps.pb(n);
                // }
                // else
                // {
                //     if (indsj.size() == 0)
                //     {
                //         gaps.pb(n - 1 - indsk[indsk.size() - 1]);
                //     }
                //     else if (indsk.size() == 0)
                //     {
                //         gaps.pb(n - 1 - indsj[indsj.size() - 1]);
                //     }
                //     else
                //     {
                //         if (indsk[indsk.size() - 1] > indsj[indsj.size() - 1])
                //         {
                //             gaps.pb(n - 1 - indsk[indsk.size() - 1]);
                //         }
                //         else
                //         {
                //             gaps.pb(n - 1 - indsj[indsj.size() - 1]);
                //         }
                //     }
                // }
                // if(j > k){
                //     ll temp = k;
                //     k = j;
                //     j = temp;
                // }
                ll mor = j ^ k;
                arr[i][j] = (arr[i][j] + (poss[mor] * arr[i - 1][k])) % 1000000007;

                // if (i == 1 && j == 2)
                // {
                //     cout << "HI" << endl;
                //     cout << arr[i][j] << " " << k << " " << currans << endl;
                // }
            }
        }
    }
    if (n % 2 == 0)
    {
        arr[m - 1][0] = arr[m - 2][0];
    }
    else
    {
        arr[m - 1][0] = 0;
    }
    for (int i = 1; i < tot; i++)
    {
        ll currans = 1;
        if (inds[i][0] % 2 == 1)
        {
            continue;
        }
        for (int j = 1; j < inds[i].size(); j++)
        {
            if ((inds[i][j] - inds[i][j - 1] - 1) % 2 == 0)
            {
                // currans = currans * mypow(2, (inds[i][j] - inds[i][j - 1] - 1) / 2, LONG_LONG_MAX);
            }
            else
            {
                currans = 0;
                break;
            }
        }
        if ((n - 1 - inds[i][inds[i].size() - 1]) % 2 == 1)
        {
            currans = 0;
        }
        arr[m - 1][0] = (arr[m - 1][0] + (currans * arr[m - 2][i]) % 1000000007) % 1000000007;
    }
    // cout << n << " " << m << endl;
    // for (int i = 0; i < m - 1; i++)
    // {
    //     for (int j = 0; j < tot; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << arr[m - 1][0] << endl;
}