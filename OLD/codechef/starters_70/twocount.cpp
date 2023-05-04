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
    ll score = 0, aminb = 0;
    for (ll i = 0; i < m; i++)
    {
        ll time1 = time[i], time2;
        if (i == 0)
            time2 = 0;
        else
            time2 = time[i - 1];
        ll timedif = time1 - time2;

        if (type[i] == 1)
        {
            if (timedif % 2 == 1)
            {
                if (aminb == 2)
                {
                    aminb = 1;
                    score++;
                }
                else if (aminb == 1)
                {
                    aminb = 2;
                    score++;
                }
                else if (aminb == 0)
                {
                    aminb = 1;
                    score++;
                }
                else if (aminb == -1)
                {
                    if (timedif > 1)
                    {
                        aminb = 2;
                        score++;
                    }
                    else
                    {
                        aminb = 0;
                    }
                }
                else
                {
                    if (timedif > 2)
                    {
                        aminb = 1;
                        score++;
                    }
                    else
                    {
                        aminb = 0;
                    }
                }
            }
            else // even time differebce
            {
                if (aminb == 2)
                {
                    score++;
                }
                else if (aminb == 1)
                {
                    score++;
                }
                else if (aminb == 0)
                {
                    aminb = 2;
                    score++;
                }
                else if (aminb == -1)
                {
                    aminb = 1;
                    score++;
                }
                else
                {
                    if (timedif > 2)
                    {
                        aminb = 2;
                        score++;
                    }
                    else
                    {
                        aminb = 0;
                    }
                }
            }
        }
        else if (type[i] == 2)
        {
            if (timedif % 2 == 1)
            {
                if (aminb == -2)
                {
                    aminb = -1;
                    score++;
                }
                else if (aminb == -1)
                {
                    aminb = -2;
                    score++;
                }
                else if (aminb == 0)
                {
                    aminb = -1;
                    score++;
                }
                else if (aminb == 1)
                {
                    if (timedif > 1)
                    {
                        aminb = -2;
                        score++;
                    }
                    else
                    {
                        aminb = 0;
                    }
                }
                else
                {
                    if (timedif > 2)
                    {
                        aminb = -1;
                        score++;
                    }
                    else
                    {
                        aminb = 0;
                    }
                }
            }
            else // even time differebce
            {
                if (aminb == -2)
                {
                    score++;
                }
                else if (aminb == -1)
                {
                    score++;
                }
                else if (aminb == 0)
                {
                    aminb = 2;
                    score++;
                }
                else if (aminb == 1)
                {
                    aminb = -1;
                    score++;
                }
                else
                {
                    if (timedif > 2)
                    {
                        aminb = -2;
                        score++;
                    }
                    else
                    {
                        aminb = 0;
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