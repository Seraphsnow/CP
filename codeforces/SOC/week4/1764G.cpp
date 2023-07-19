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
    ll n;
    cin >> n;
    ll min = 1, max = n;
    ll small = 0, large = 0;
    if (n % 2 == 1)
    {
        while (true)
        {
            if (min == max)
            {
                cout << "! " << min << endl;
                return 0;
            }
            // cout << min << " " << max << endl;
            ll mid;
            mid = (min + max) / 2;
            cout << "? " << 1 << " " << mid << " " << 2 << endl;
            cout.flush();
            ll less;
            cin >> less;
            cout << "? " << mid + 1 << " " << n << " " << 2 << endl;
            cout.flush();
            ll more;
            cin >> more;
            if (2 * less - mid > 2 * more - (n - mid))
            {
                max = mid;
                large = (n - 1) / 2 - less + 1;
            }
            else if (2 * less - mid < 2 * more - (n - mid))
            {
                min = mid + 1;
                small = (n - 1) / 2 - more + 1;
            }
            else
            {
                cout << "error" << endl;
            }
        }
    }
    else
    {
        ll nbelow = 0, nabove = 0;
        ll prevmin, prevmax, prevless, prevmore;
        while (true)
        {
            if (min == max)
            {
                cout << "! " << min << endl;
                return 0;
            }
            else if (min == max - 1)
            {
                if (nabove != nbelow)
                {
                    if (prevmin < min)
                    {
                        cout << "? " << max << " " << n << " " << 2 << endl;
                        ll more;
                        cin >> more;
                        if (prevmore == more)
                        {
                            cout << "! " << max << endl;
                            return 0;
                        }
                        else
                        {
                            if ((prevless + prevmore) == ((n / 2) + 1))
                            {
                                cout << "! " << min << endl;
                                return 0;
                            }
                            else
                            {
                                cout << "! " << max << endl;
                                return 0;
                            }
                        }
                    }
                    else
                    {
                        cout << "? " << 1 << " " << min << " " << 2 << endl;
                        ll less;
                        cin >> less;
                        if (prevless == less)
                        {
                            cout << "! " << min << endl;
                            return 0;
                        }
                        else
                        {
                            if ((prevless + prevmore) == ((n / 2) + 1))
                            {
                                cout << "! " << max << endl;
                                return 0;
                            }
                            else
                            {
                                cout << "! " << min << endl;
                                return 0;
                            }
                        }
                    }
                }
                else
                {
                    cout << "? " << 1 << " " << min << " " << n << endl;
                    cout.flush();
                    ll less;
                    cin >> less;
                    if (less == 2)
                    {
                        cout << "! " << max << endl;
                        return 0;
                    }
                    else
                    {
                        cout << "! " << min << endl;
                        return 0;
                    }
                }
            }
            // cout << min << " " << max << endl;
            ll mid;
            mid = (min + max) / 2;
            cout << "? " << 1 << " " << mid << " " << 2 << endl;
            cout.flush();
            ll less;
            cin >> less;
            cout << "? " << mid + 1 << " " << n << " " << 2 << endl;
            cout.flush();
            ll more;
            cin >> more;
            prevmin = min;
            prevmax = max;
            prevless = less;
            prevmore = more;
            if (2 * less - mid - nbelow > 2 * more - (n - mid) - nabove)
            {
                max = mid;
                large = (n - 1) / 2 - less + 1;
            }
            else if (2 * less - mid - nbelow < 2 * more - (n - mid) - nabove)
            {
                min = mid + 1;
                small = (n - 1) / 2 - more + 1;
            }
            else
            {
                if (mid != 1)
                {
                    cout << "? " << 1 << " " << mid << " " << n << endl;
                    ll side;
                    cin >> side;
                    if (side == 2)
                    {
                        nbelow = 1;
                    }
                    else
                    {
                        nabove = 1;
                    }
                }
                else
                {
                    cout << "? " << mid + 1 << " " << n << " " << n << endl;
                    ll side;
                    cin >> side;
                    if (side == 1)
                    {
                        nbelow = 1;
                    }
                    else
                    {
                        nabove = 1;
                    }
                }

                if (2 * less - mid - nbelow > 2 * more - (n - mid) - nabove)
                {
                    max = mid;
                    large = (n - 1) / 2 - less + 1;
                }
                else if (2 * less - mid - nbelow < 2 * more - (n - mid) - nabove)
                {
                    min = mid + 1;
                    small = (n - 1) / 2 - more + 1;
                }
            }
        }
    }
}