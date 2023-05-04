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

ll mod = 2*7*13*3*19*5*11*17;

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

ll inspect0(ll worry)
{
    return worry * 5;
}

ll inspect1(ll worry)
{
    return worry*worry;
}

ll inspect2(ll worry)
{
    return worry +1;
}

ll inspect3(ll worry)
{
    return worry + 6;
}

ll inspect4(ll worry)
{
    return worry*17;
}

ll inspect5(ll worry)
{
    return worry + 8;
}

ll inspect6(ll worry)
{
    return worry + 7;
}

ll inspect7(ll worry)
{
    return worry + 5;
}

ll test0(ll worry)
{
    if (worry % 2 == 0)
        return 2;
    else
        return 1;
}

int test1(ll worry)
{
    if (worry % 7 == 0)
        return 3;
    else
        return 6;
}

int test2(ll worry)
{
    if (worry % 13 == 0)
        return 1;
    else
        return 3;
}

int test3(ll worry)
{
    if (worry % 3 == 0)
        return 6;
    else
        return 4;
}

int test4(ll worry)
{
    if (worry % 19 == 0)
        return 7;
    else
        return 5;
}

int test5(ll worry)
{
    if (worry % 5 == 0)
        return 0;
    else
        return 2;
}

int test6(ll worry)
{
    if (worry % 11 == 0)
        return 7;
    else
        return 4;
}

int test7(ll worry)
{
    if (worry % 17 == 0)
        return 5;
    else
        return 0;
}

int main(int argc, char *argv[])
{
    vector<ll> monkey[8];
    ll inspect[8];
    monkey[0].pb(50);
    monkey[0].pb(70);
    monkey[0].pb(89);
    monkey[0].pb(75);
    monkey[0].pb(66);
    monkey[0].pb(66);
    monkey[1].pb(85);
    monkey[2].pb(66);
    monkey[2].pb(51);
    monkey[2].pb(71);
    monkey[2].pb(76);
    monkey[2].pb(58);
    monkey[2].pb(55);
    monkey[2].pb(58);
    monkey[2].pb(60);
    monkey[3].pb(79);
    monkey[3].pb(52);
    monkey[3].pb(55);
    monkey[3].pb(51);
    monkey[4].pb(69);
    monkey[4].pb(92);
    monkey[5].pb(71);
    monkey[5].pb(76);
    monkey[5].pb(73);
    monkey[5].pb(98);
    monkey[5].pb(67);
    monkey[5].pb(79);
    monkey[5].pb(99);
    monkey[6].pb(82);
    monkey[6].pb(76);
    monkey[6].pb(69);
    monkey[6].pb(69);
    monkey[6].pb(57);
    monkey[7].pb(65);
    monkey[7].pb(79);
    monkey[7].pb(86);
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < monkey[j].size();)
            {
                ll worry = monkey[j][k];
                inspect[j]++;
                if (j == 0)
                    worry = inspect0(worry);
                if (j == 1)
                    worry = inspect1(worry);
                if (j == 2)
                    worry = inspect2(worry);
                if (j == 3)
                    worry = inspect3(worry);
                if (j == 4)
                    worry = inspect4(worry);
                if (j == 5)
                    worry = inspect5(worry);
                if (j == 6)
                    worry = inspect6(worry);
                if (j == 7)
                    worry = inspect7(worry);
                int newmonkey;
                worry = worry % mod;
                if (j == 0)
                    newmonkey = test0(worry);
                if (j == 1)
                    newmonkey = test1(worry);
                if (j == 2)
                    newmonkey = test2(worry);
                if (j == 3)
                    newmonkey = test3(worry);
                if (j == 4)
                    newmonkey = test4(worry);
                if (j == 5)
                    newmonkey = test5(worry);
                if (j == 6)
                    newmonkey = test6(worry);
                if (j == 7)
                    newmonkey = test7(worry);
                monkey[newmonkey].pb(worry);
                monkey[j].erase(monkey[j].begin() + k);
            }
        }
    }
    for(ll i = 0; i < 8; i++){
        cout << inspect[i] << endl;
    }
}