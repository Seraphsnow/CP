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

void solve()
{
    ll n, m;
    cin >> n >> m;
    ll time[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> time[i];
    }
    ll type[m];
    for (ll i = 0; i < m; i++)
    {
        cin >> type[i];
    }
    ll score = 0, a = 0, b = 0;
    for (ll i = 0; i < m; i++)
    {
        if (i == 0)
        {
            score++;

            if (type[0] == 1)
            {
                a = 2 - (time[0] % 2);
            }
            else
            {
                b = 2 - (time[0] % 2);
            }
        }
        else
        {
            if ((time[i] - time[i - 1]) % 2)
            {
                if (type[i] == 1)
                {
                    if (a == 2)
                    {
                        a = 1;
                        b = 0;
                        score++;
                    }
                    else if (a == 1)
                    {
                        a = 2;
                        b = 0;
                        score++;
                    }
                    else if (b == 0)
                    {
                        a = 1;
                        b = 0;
                        score++;
                    }
                    else if (b == 1)
                    {
                        if ((time[i] - time[i - 1]) >= 3)
                        {
                            a = 2;
                            b = 0;
                            score++;
                        }
                        else
                        {
                            a = 0;
                            b = 0;
                        }
                    }
                    else if (b == 2)
                    {
                        if ((time[i] - time[i - 1]) >= 3)
                        {
                            a = 1;
                            b = 0;
                            score++;
                        }
                        else
                        {
                            a = 0;
                            b = 0;
                        }
                    }
                }
                else
                {
                    if (b == 2)
                    {
                        b = 1;
                        a = 0;
                        score++;
                    }
                    else if (b == 1)
                    {
                        b = 2;
                        a = 0;
                        score++;
                    }
                    else if (a == 0)
                    {
                        b = 1;
                        a = 0;
                        score++;
                    }
                    else if (a == 1)
                    {
                        if ((time[i] - time[i - 1]) >= 3)
                        {
                            b = 2;
                            a = 0;
                            score++;
                        }
                        else
                        {
                            a = 0;
                            b = 0;
                        }
                    }
                    else if (a == 2)
                    {
                        if ((time[i] - time[i - 1]) >= 3)
                        {
                            b = 1;
                            a = 0;
                            score++;
                        }
                        else
                        {
                            a = 0;
                            b = 0;
                        }
                    }
                }
            }
            else
            {
                if (type[i] == 1)
                {
                    if (a == 2 || a == 1)
                    {
                        b = 0;
                        score++;
                    }
                    else if (b == 0)
                    {
                        a = 2;
                        score++;
                    }
                    else if (b == 1)
                    {
                        a = 1;
                        b = 0;
                        score++;
                    }
                    else if (b == 2)
                    {
                        if ((time[i] - time[i - 1]) >= 4)
                        {
                            a = 2;
                            b = 0;
                            score++;
                        }
                        else
                        {
                            a = 0;
                            b = 0;
                        }
                    }
                }
                else
                {
                    if (b == 2 || b == 1)
                    {
                        a = 0;
                        score++;
                    }
                    else if (a == 0)
                    {
                        b = 2;
                        
                        score++;
                    }
                    else if (a == 1)
                    {
                        b = 1;
                        a = 0;
                        score++;
                    }
                    else if (a == 2)
                    {
                        if ((time[i] - time[i - 1]) >= 4)
                        {
                            b = 2;
                            a = 0;
                            score++;
                        }
                        else
                        {
                            a = 0;
                            b = 0;
                        }
                    }
                }
            }
        }
    }
    cout << score << endl;
}

int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}