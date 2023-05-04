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
    set<pair<ll, ll>> coords;
    coords.insert({x[1], y[1]});
    if (myfile.is_open())
    {
        while (myfile)
        {
            if (myfile.eof())
                break;
            getline(myfile, mystring);
            vector<string> strings = adv_tokenizer(mystring, ' ');
            for (int i = 0; i < stoi(strings[1]); i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (x[j] == x[j+1])
                    {
                        if (y[j] == y[j+1])
                        {
                            if (strings[0] == "R")
                            {
                                x[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                x[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                y[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                y[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else if (y[0] == y[1] + 1)
                        {
                            if (strings[0] == "R")
                            {
                                x[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                x[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                coords.insert({x[1], y[1]});
                                y[0]++;
                                y[1]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                y[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else if (y[0] == y[1] - 1)
                        {
                            if (strings[0] == "R")
                            {
                                x[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                x[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")

                            {
                                y[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                coords.insert({x[1], y[1]});
                                y[0]--;
                                y[1]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else
                        {
                            cout << "error\n";
                        }
                    }
                    else if (x[0] == x[1] + 1)
                    {
                        if (y[0] == y[1])
                        {
                            if (strings[0] == "R")
                            {
                                coords.insert({x[1], y[1]});
                                x[0]++;
                                x[1]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                x[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                y[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                y[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else if (y[0] == y[1] + 1)
                        {
                            if (strings[0] == "R")
                            {
                                coords.insert({x[1], y[1]});
                                x[0]++;
                                x[1]++;
                                y[1]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")

                            {
                                x[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                coords.insert({x[1], y[1]});
                                y[0]++;
                                x[1]++;
                                y[1]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                y[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else if (y[0] == y[1] - 1)
                        {
                            if (strings[0] == "R")
                            {
                                coords.insert({x[1], y[1]});
                                x[0]++;
                                x[1]++;
                                y[1]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                x[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                y[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                coords.insert({x[1], y[1]});
                                y[0]--;
                                x[1]++;
                                y[1]--;
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else
                        {
                            cout << "error\n";
                        }
                    }
                    else if (x[0] == x[1] - 1)
                    {
                        if (y[0] == y[1])
                        {
                            if (strings[0] == "R")
                            {
                                x[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                coords.insert({x[1], y[1]});
                                x[0]--;
                                x[1]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                y[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                y[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else if (y[0] == y[1] + 1)
                        {
                            if (strings[0] == "R")
                            {
                                x[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                coords.insert({x[1], y[1]});
                                x[0]--;
                                x[1]--;
                                y[1]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                coords.insert({x[1], y[1]});
                                y[0]++;
                                x[1]--;
                                y[1]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                y[0]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else if (y[0] == y[1] - 1)
                        {
                            if (strings[0] == "R")
                            {
                                x[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "L")
                            {
                                coords.insert({x[1], y[1]});
                                x[0]--;
                                x[1]--;
                                y[1]--;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "U")
                            {
                                y[0]++;
                                coords.insert({x[1], y[1]});
                            }
                            else if (strings[0] == "D")
                            {
                                coords.insert({x[1], y[1]});
                                y[0]--;
                                x[1]--;
                                y[1]--;
                                coords.insert({x[1], y[1]});
                            }
                            else
                            {
                                cout << "eror\n";
                            }
                        }
                        else
                        {
                            cout << "error\n";
                        }
                    }
                    else
                    {
                        cout << "error\n";
                    }
                }
            }
        }
        cout << coords.size() << endl;
    }
}