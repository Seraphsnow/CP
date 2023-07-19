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

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<pair<pll, ll>> conts;
    if (s[0] == '(')
        conts.pb({{1, 1}, 1});
    else
    {
        conts.pb({{1, 1}, 0});
    }
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
        {
            conts.back().fi.se++;
        }
        else
        {
            conts.pb({{i + 1, 1}, 1 - conts.back().se});
        }
    }
    set<pll> start1, end0;
    for (int i = 0; i < conts.size(); i++)
    {
        if (conts[i].fi.se >= 2)
        {
            if (conts[i].se)
            {
                start1.insert(conts[i].fi);
            }
            else
            {
                end0.insert(conts[i].fi);
            }
        }
    }

    cout << s << endl;
    for (auto itr = start1.begin(); itr != start1.end(); itr++)
    {
        cout << (*itr).fi << " " << (*itr).se << endl;
    }
    cout << endl;
    for (auto itr = end0.begin(); itr != end0.end(); itr++)
    {
        cout << (*itr).fi << " " << (*itr).se << endl;
    }

    for (int i = 0; i < q; i++)
    {
        ll ind;
        cin >> ind;
        cout << endl
             << endl;
        cout << ind << endl;
        if (n % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
        if (s[ind - 1] == '(')
        {
            s[ind - 1] = ')';
        }
        else
        {
            s[ind - 1] = '(';
        }
        if (s[ind - 1] == '(')
        {
            if (ind == 1)
            {
                if (s[1] == '(')
                {
                    if (start1.size() && (*start1.begin()).fi == 2)
                    {
                        auto it = start1.begin();
                        start1.insert({1, (*it).se + 1});
                        start1.erase(it);
                    }
                    else
                    {
                        start1.insert({1, 2});
                    }
                }
                else
                {
                    auto it = end0.begin();
                    if ((*it).se > 2)
                    {
                        end0.insert({2, (*it).se - 1});
                    }
                    end0.erase(*it);
                }
            }
            else if (ind == n)
            {
                if (s[n - 2] == '(')
                {
                    auto it = next(start1.end(), -1);
                    if (start1.size() && (*it).fi + (*it).se == n)
                    {
                        start1.insert({(*it).fi, (*it).se + 1});
                        start1.erase(it);
                    }
                    else
                    {
                        start1.insert({n - 1, 2});
                    }
                }
                else
                {
                    auto it = next(end0.end(), -1);
                    if ((*it).se > 2)
                    {
                        end0.insert({(*it).fi, (*it).se - 1});
                    }
                    end0.erase(*it);
                }
            }
            else
            {
                if (s[ind - 2] == '(')
                {
                    if (s[ind] == '(')
                    {
                        if (start1.size())
                        {
                            auto it = start1.lower_bound({ind, 0});
                            if (it == start1.begin())
                            {
                                if ((*it).fi == ind + 1)
                                {
                                    start1.insert({ind - 1, (*it).se + 2});
                                    start1.erase(it);
                                }
                                else
                                {
                                    start1.insert({ind - 1, 3});
                                }
                            }
                            else
                            {
                                auto it2 = next(it, -1);
                                if ((*it2).fi + (*it2).se == ind)
                                {
                                    if ((*it).fi == ind + 1)
                                    {
                                        start1.insert({(*it2).fi, (*it).se + 1 + (*it2).se});
                                        start1.erase(it);
                                    }
                                    else
                                    {
                                        start1.insert({(*it2).fi, 2 + (*it2).se});
                                    }
                                    start1.erase(it2);
                                }
                                else
                                {
                                    if ((*it).fi == ind + 1)
                                    {
                                        start1.insert({ind - 1, (*it).se + 2});
                                        start1.erase(it);
                                    }
                                    else
                                    {
                                        start1.insert({ind - 1, 3});
                                    }
                                }
                            }
                        }
                        else
                        {
                            start1.insert({ind - 1, 3});
                        }
                    }
                    else
                    {
                        if (start1.size())
                        {
                            auto it = start1.lower_bound({ind, 0});
                            if (it == start1.begin())
                            {
                                start1.insert({ind - 1, 2});
                            }
                            else
                            {
                                auto it2 = next(it, -1);
                                if ((*it2).fi + (*it2).se == ind)
                                {

                                    start1.insert({(*it2).fi, 1 + (*it2).se});

                                    start1.erase(it2);
                                }
                                else
                                {
                                    start1.insert({ind - 1, 2});
                                }
                            }
                        }
                        else
                        {
                            start1.insert({ind - 1, 2});
                        }

                        auto it = end0.lower_bound({ind, 0});
                        if ((*it).se > 2)
                        {
                            end0.insert({ind + 1, (*it).se - 1});
                        }
                        end0.erase(it);
                    }
                }
                else
                {
                    if (s[ind] == '(')
                    {
                        if (start1.size())
                        {
                            auto it = start1.lower_bound({ind, 0});
                            if ((*it).fi == ind + 1)
                            {
                                start1.insert({ind, (*it).se + 1});
                                start1.erase(it);
                            }
                            else
                            {
                                start1.insert({ind, 2});
                            }
                        }
                        else
                        {
                            start1.insert({ind, 2});
                        }
                        auto it2 = end0.lower_bound({ind, 0});
                        it2 = next(it2, -1);
                        if ((*it2).se > 2)
                        {
                            end0.insert({(*it2).fi, (*it2).se - 1});
                        }
                        end0.erase(it2);
                    }
                    else
                    {
                        auto i1 = end0.lower_bound({ind, 0});
                        i1 = next(i1, -1);
                        ll l = (*i1).fi, r = (*i1).se + l - 1;
                        if (l < ind - 1)
                        {
                            end0.insert({l, ind - l});
                        }
                        if (r > ind + 1)
                        {
                            end0.insert({ind + 1, r - ind});
                        }
                        end0.erase(i1);
                    }
                }
            }
        }
        else
        {
            if (ind == 1)
            {
                if (s[1] == ')')
                {
                    if (end0.size() && (*end0.begin()).fi == 2)
                    {
                        auto it = end0.begin();
                        end0.insert({1, (*it).se + 1});
                        end0.erase(it);
                    }
                    else
                    {
                        end0.insert({1, 2});
                    }
                }
                else
                {
                    auto it = start1.begin();
                    if ((*it).se > 2)
                    {
                        start1.insert({2, (*it).se - 1});
                    }
                    start1.erase(*it);
                }
            }
            else if (ind == n)
            {
                if (s[n - 2] == ')')
                {
                    auto it = next(end0.end(), -1);
                    if (end0.size() && (*it).fi + (*it).se == n)
                    {
                        end0.insert({(*it).fi, (*it).se + 1});
                        end0.erase(it);
                    }
                    else
                    {
                        end0.insert({n - 1, 2});
                    }
                }
                else
                {
                    auto it = next(start1.end(), -1);
                    if ((*it).se > 2)
                    {
                        start1.insert({(*it).fi, (*it).se - 1});
                    }
                    start1.erase(*it);
                }
            }
            else
            {
                if (s[ind - 2] == ')')
                {
                    if (s[ind] == ')')
                    {
                        if (end0.size())
                        {
                            auto it = end0.lower_bound({ind, 0});
                            if (it == end0.begin())
                            {
                                if ((*it).fi == ind + 1)
                                {
                                    end0.insert({ind - 1, (*it).se + 2});
                                    end0.erase(it);
                                }
                                else
                                {
                                    end0.insert({ind - 1, 3});
                                }
                            }
                            else
                            {
                                auto it2 = next(it, -1);
                                if ((*it2).fi + (*it2).se == ind)
                                {
                                    if ((*it).fi == ind + 1)
                                    {
                                        end0.insert({(*it2).fi, (*it).se + 1 + (*it2).se});
                                        end0.erase(it);
                                    }
                                    else
                                    {
                                        end0.insert({(*it2).fi, 2 + (*it2).se});
                                    }
                                    end0.erase(it2);
                                }
                                else
                                {
                                    if ((*it).fi == ind + 1)
                                    {
                                        end0.insert({ind - 1, (*it).se + 2});
                                        end0.erase(it);
                                    }
                                    else
                                    {
                                        end0.insert({ind - 1, 3});
                                    }
                                }
                            }
                        }
                        else
                        {
                            end0.insert({ind - 1, 3});
                        }
                    }
                    else
                    {
                        if (end0.size())
                        {
                            auto it = end0.lower_bound({ind, 0});
                            if (it == end0.begin())
                            {
                                end0.insert({ind - 1, 2});
                            }
                            else
                            {
                                auto it2 = next(it, -1);
                                if ((*it2).fi + (*it2).se == ind)
                                {

                                    end0.insert({(*it2).fi, 1 + (*it2).se});

                                    end0.erase(it2);
                                }
                                else
                                {
                                    end0.insert({ind - 1, 2});
                                }
                            }
                        }
                        else
                        {
                            end0.insert({ind, 2});
                        }

                        auto it = start1.lower_bound({ind, 0});
                        if ((*it).se > 2)
                        {
                            start1.insert({ind + 1, (*it).se - 1});
                        }
                        start1.erase(it);
                    }
                }
                else
                {
                    if (s[ind] == ')')
                    {
                        if (end0.size())
                        {
                            auto it = end0.lower_bound({ind, 0});
                            if ((*it).fi == ind + 1)
                            {
                                end0.insert({ind, (*it).se + 1});
                                end0.erase(it);
                            }
                            else
                            {
                                end0.insert({ind, 2});
                            }
                        }
                        else
                        {
                            end0.insert({ind - 1, 2});
                        }
                        auto it2 = start1.lower_bound({ind, 0});
                        it2 = next(it2, -1);
                        if ((*it2).se > 2)
                        {
                            start1.insert({(*it2).fi, (*it2).se - 1});
                        }
                        start1.erase(it2);
                    }
                    else
                    {
                        auto i1 = start1.lower_bound({ind, 0});
                        i1 = next(i1, -1);
                        ll l = (*i1).fi, r = (*i1).se + l - 1;
                        if (l < ind - 1)
                        {
                            start1.insert({l, ind - l});
                        }
                        if (r > ind + 1)
                        {
                            start1.insert({ind + 1, r - ind});
                        }
                        start1.erase(i1);
                    }
                }
            }
        }
        
        
        
        cout << s << endl;
        for (auto itr = start1.begin(); itr != start1.end(); itr++)
        {
            cout << (*itr).fi << " " << (*itr).se << endl;
        }
        cout << endl;
        for (auto itr = end0.begin(); itr != end0.end(); itr++)
        {
            cout << (*itr).fi << " " << (*itr).se << endl;
        }
        if (s[0] == '(' && s[n - 1] == ')')
        {
            if (start1.size() && end0.size())
            {
                auto i1 = *start1.begin(), i2 = *end0.begin(), i3 = *next(start1.end(), -1), i4 = *next(end0.end(), -1);
                if (i1.fi < i2.fi && i3.fi < i4.fi)
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
            }
            else if (start1.size() == 0 && end0.size() == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            cout << "NO\n";
        }
    }
}