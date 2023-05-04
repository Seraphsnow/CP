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
    ll headx = 100, heady = 100, tailx = 100, taily = 100;
    set<pair<ll,ll>> coords;
    coords.insert({tailx,taily});
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
                if (headx == tailx)
                {
                    if (heady == taily)
                    {
                        if (strings[0] == "R")
                        {
                            headx++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            headx--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            heady++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            heady--;
                            coords.insert({tailx,taily});
                        }
                        else
                        {
                            cout << "eror\n";
                        }
                    }
                    else if (heady == taily + 1)
                    {
                        if (strings[0] == "R")
                        {
                            headx++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            headx--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            coords.insert({tailx,taily});
                            heady++;
                            taily++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            heady--;
                            coords.insert({tailx,taily});
                        }
                        else
                        {
                            cout << "eror\n";
                        }
                    }
                    else if (heady == taily - 1)
                    {
                        if (strings[0] == "R")
                        {
                            headx++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            headx--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")

                        {
                            heady++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            coords.insert({tailx,taily});
                            heady--;
                            taily--;
                            coords.insert({tailx,taily});
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
                else if (headx == tailx + 1)
                {
                    if (heady == taily)
                    {
                        if (strings[0] == "R")
                        {
                            coords.insert({tailx,taily});
                            headx++;
                            tailx++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            headx--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            heady++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            heady--;
                            coords.insert({tailx,taily});
                        }
                        else
                        {
                            cout << "eror\n";
                        }
                    }
                    else if (heady == taily + 1)
                    {
                        if (strings[0] == "R")
                        {
                            coords.insert({tailx,taily});
                            headx++;
                            tailx++;
                            taily++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")

                        {
                            headx--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            coords.insert({tailx,taily});
                            heady++;
                            tailx++;
                            taily++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            heady--;
                            coords.insert({tailx,taily});
                        }
                        else
                        {
                            cout << "eror\n";
                        }
                    }
                    else if (heady == taily - 1)
                    {
                        if (strings[0] == "R")
                        {
                            coords.insert({tailx,taily});
                            headx++;
                            tailx++;
                            taily--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            headx--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            heady++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            coords.insert({tailx,taily});
                            heady--;
                            tailx++;
                            taily--;
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
                else if (headx == tailx - 1)
                {
                    if (heady == taily)
                    {
                        if (strings[0] == "R")
                        {
                            headx++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            coords.insert({tailx,taily});
                            headx--;
                            tailx--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            heady++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            heady--;
                            coords.insert({tailx,taily});
                        }
                        else
                        {
                            cout << "eror\n";
                        }
                    }
                    else if (heady == taily + 1)
                    {
                        if (strings[0] == "R")
                        {
                            headx++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            coords.insert({tailx,taily});
                            headx--;
                            tailx--;
                            taily++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            coords.insert({tailx,taily});
                            heady++;
                            tailx--;
                            taily++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            heady--;
                            coords.insert({tailx,taily});
                        }
                        else
                        {
                            cout << "eror\n";
                        }
                    }
                    else if (heady == taily - 1)
                    {
                        if (strings[0] == "R")
                        {
                            headx++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "L")
                        {
                            coords.insert({tailx,taily});
                            headx--;
                            tailx--;
                            taily--;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "U")
                        {
                            heady++;
                            coords.insert({tailx,taily});
                        }
                        else if (strings[0] == "D")
                        {
                            coords.insert({tailx,taily});
                            heady--;
                            tailx--;
                            taily--;
                            coords.insert({tailx,taily});
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
        cout << coords.size() << endl;
    }
}