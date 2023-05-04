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

vector<string> adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> mystring;
    while (!ss.eof())
    {
        getline(ss, word, del);
        mystring.pb(word);
    }
    return mystring;
}

int main(int argc, char *argv[])
{
    ifstream myfile("test.txt");
    string mystring;
    ll x[10], y[10];
    for (int i = 0; i < 10; i++)
    {
        x[i] = 0;
        y[i] = 0;
    }
    set<pll> coords;

    coords.insert({x[1], y[1]});
    if (myfile.is_open())
    {
        while (myfile)
        {
            if (myfile.eof())
                break;
            getline(myfile, mystring);
            vector<string> strings = adv_tokenizer(mystring, ' ');
            if (strings[0] == "R")
            {
                ll right = stoi(strings[1]);
                for (int i = 0; i < right; i++)
                {
                    x[0]++;
                    for (int i = 0; i < 9; i++)
                    {
                        if (x[0] == x[1] || x[0] == x[1] + 1)
                        {
                        }
                        else
                        {
                            x[1]++;
                            if (y[0] == y[1] + 1)
                            {
                                y[1]++;
                            }
                            else if (y[0] == y[1] - 1)
                            {
                                y[1]--;
                            }
                        }
                    }
                }
            }
            else if (strings[0] == "L")
            {
                ll left = stoi(strings[1]);
                for (int i = 0; i < left; i++)
                {
                    x[0]--;
                    if (x[0] == x[1] || x[0] == x[1] - 1)
                    {
                    }
                    else
                    {
                        x[1]--;
                        if (y[0] == y[1] + 1)
                        {
                            y[1]++;
                        }
                        else if (y[0] == y[1] - 1)
                        {
                            y[1]--;
                        }
                    }
                    coords.insert({x[1], y[1]});
                }
            }
            else if (strings[0] == "U")
            {
                ll up = stoi(strings[1]);
                for (int i = 0; i < up; i++)
                {
                    y[0]++;
                    if (y[0] == y[1] || y[0] == y[1] + 1)
                    {
                    }
                    else
                    {
                        y[1]++;
                        if (x[0] == x[1] + 1)
                        {
                            x[1]++;
                        }
                        else if (x[0] == x[1] - 1)
                        {
                            x[1]--;
                        }
                    }
                    coords.insert({x[1], y[1]});
                }
            }
            else
            {
                ll down = stoi(strings[1]);
                for (int i = 0; i < down; i++)
                {
                    y[0]--;
                    if (y[0] == y[1] || y[0] == y[1] - 1)
                    {
                    }
                    else
                    {
                        y[1]--;
                        if (x[0] == x[1] + 1)
                        {
                            x[1]++;
                        }
                        else if (x[0] == x[1] - 1)
                        {
                            x[1]--;
                        }
                    }
                    coords.insert({x[1], y[1]});
                }
            }
        }
        cout << coords.size() << endl;
    }
}