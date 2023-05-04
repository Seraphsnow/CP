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

int main(int argc, char *argv[])
{
    ifstream myfile("day3.txt");
    string mystring[3];
    ll score = 0;
    if (myfile.is_open())
    {
        while (myfile)
        {
            bool found = false;
            if (myfile.eof())
                break;
            getline(myfile, mystring[0]);
            getline(myfile, mystring[1]);
            getline(myfile, mystring[2]);
            for (int i = 0; i < mystring[0].size(); i++)
            {
                char mychar = mystring[0][i];
                for (int j = 0; j < mystring[1].size(); j++)
                {
                    if (mystring[1][j] == mychar)
                    {
                        for (int k = 0; k < mystring[2].size(); k++)
                        {
                            if (mystring[2][k] == mychar)
                            {
                                found = true;
                                if (mychar > 96)
                                {
                                    score += mychar - 96;
                                }
                                else
                                {
                                    score += mychar - 64 + 26;
                                }
                            }
                            if (found)
                                break;
                        }
                    }
                    if (found)
                        break;
                }
                if (found)
                    break;
            }
        }
        cout << score << endl;
    }
}