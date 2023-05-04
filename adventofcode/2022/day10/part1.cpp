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
    ll score = 0;
    if (myfile.is_open())
    {
        ll cyclenum = 0, x = 1;
        while (myfile)
        {
            if (myfile.eof())
                break;
            getline(myfile, mystring);
            if (mystring == "noop")
            {
                cyclenum++;
                if (cyclenum % 40 == 20)
                {
                    score += cyclenum * x;
                    cout << score << " " << cyclenum << " " << x << endl;
                }
            }
            else
            {
                vector<string> strings = adv_tokenizer(mystring, ' ');
                cyclenum++;
                if (cyclenum % 40 == 20)
                {
                    score += cyclenum * x;
                    cout << score << " " << cyclenum << " " << x << endl;
                }
                cyclenum++;
                if (cyclenum % 40 == 20)
                {
                    score += cyclenum * x;
                    cout << score << " " << cyclenum << " " << x << endl;
                }
                x += stoi(strings[1]);
            }
        }
        cout << score << endl;
    }
}