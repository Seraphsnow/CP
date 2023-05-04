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
    coords.insert({x[9], y[9]});
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
                for (int i = 0; i < stoi(strings[1]); i++)
                {
                    x[0]++;
                    for (int j = 0; j < 9; j++)
                    {
                        if ((x[j] - x[j + 1]) < 2 && (x[j] - x[j + 1]) > -2 && (y[j] - y[j + 1]) < 2 && (y[j] - y[j + 1]) > -2)
                        {
                            continue;
                        }
                        else if ((x[j] - x[j + 1]) == 2 || (x[j] - x[j + 1]) == -2 || (y[j] - y[j + 1]) == 2 || (y[j] - y[j + 1]) == -2)
                        {
                            if (x[j] - x[j + 1] == 2)
                            {
                                x[j + 1]++;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (x[j] - x[j + 1] == -2)
                            {
                                x[j + 1]--;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (y[j] - y[j + 1] == 2)
                            {
                                y[j + 1]++;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                            else
                            {
                                y[j + 1]--;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                        }
                        else
                        {
                            cout << "errorR\n";
                        }
                    }
                    coords.insert({x[9], y[9]});
                }
            }
            else if (strings[0] == "L")
            {
                for (int i = 0; i < stoi(strings[1]); i++)
                {
                    x[0]--;
                    for (int j = 0; j < 9; j++)
                    {
                        if ((x[j] - x[j + 1]) < 2 && (x[j] - x[j + 1]) > -2 && (y[j] - y[j + 1]) < 2 && (y[j] - y[j + 1]) > -2)
                        {
                            continue;
                        }
                        else if ((x[j] - x[j + 1]) == 2 || (x[j] - x[j + 1]) == -2 || (y[j] - y[j + 1]) == 2 || (y[j] - y[j + 1]) == -2)
                        {
                            if (x[j] - x[j + 1] == 2)
                            {
                                x[j + 1]++;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (x[j] - x[j + 1] == -2)
                            {
                                x[j + 1]--;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (y[j] - y[j + 1] == 2)
                            {
                                y[j + 1]++;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                            else
                            {
                                y[j + 1]--;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                        }
                        else
                        {
                            cout << "errorL\n";
                        }
                    }
                    coords.insert({x[9], y[9]});
                }
            }
            else if (strings[0] == "U")
            {
                for (int i = 0; i < stoi(strings[1]); i++)
                {
                    y[0]++;
                    for (int j = 0; j < 9; j++)
                    {
                        if ((x[j] - x[j + 1]) < 2 && (x[j] - x[j + 1]) > -2 && (y[j] - y[j + 1]) < 2 && (y[j] - y[j + 1]) > -2)
                        {
                            continue;
                        }
                        else if ((x[j] - x[j + 1]) == 2 || (x[j] - x[j + 1]) == -2 || (y[j] - y[j + 1]) == 2 || (y[j] - y[j + 1]) == -2)
                        {
                            if (x[j] - x[j + 1] == 2)
                            {
                                x[j + 1]++;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (x[j] - x[j + 1] == -2)
                            {
                                x[j + 1]--;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (y[j] - y[j + 1] == 2)
                            {
                                y[j + 1]++;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                            else
                            {
                                y[j + 1]--;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                        }
                        else
                        {
                            cout << "errorU\n";
                        }
                    }
                    coords.insert({x[9], y[9]});
                }
            }
            else if (strings[0] == "D")
            {
                for (int i = 0; i < stoi(strings[1]); i++)
                {
                    y[0]--;
                    for (int j = 0; j < 9; j++)
                    {
                        if ((x[j] - x[j + 1]) < 2 && (x[j] - x[j + 1]) > -2 && (y[j] - y[j + 1]) < 2 && (y[j] - y[j + 1]) > -2)
                        {
                            continue;
                        }
                        else if ((x[j] - x[j + 1]) == 2 || (x[j] - x[j + 1]) == -2 || (y[j] - y[j + 1]) == 2 || (y[j] - y[j + 1]) == -2)
                        {
                            if (x[j] - x[j + 1] == 2)
                            {
                                x[j + 1]++;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (x[j] - x[j + 1] == -2)
                            {
                                x[j + 1]--;
                                if (y[j] > y[j + 1])
                                {
                                    y[j + 1]++;
                                }
                                else if (y[j] < y[j + 1])
                                {
                                    y[j + 1]--;
                                }
                            }
                            else if (y[j] - y[j + 1] == 2)
                            {
                                y[j + 1]++;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                            else
                            {
                                y[j + 1]--;
                                if (x[j] > x[j + 1])
                                {
                                    x[j + 1]++;
                                }
                                else if (x[j] < x[j + 1])
                                {
                                    x[j + 1]--;
                                }
                            }
                        }
                        else
                        {
                            cout << "errorD\n";
                        }
                    }
                    coords.insert({x[9], y[9]});
                }
            }
            else
            {
                cout << "error5\n";
            }
        }
        cout << coords.size() << endl;
    }
}