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
    ifstream myfile("txt.txt");
    string mystring;
    int arr[99][99];
    bool visible[99][99];
    if (myfile.is_open())
    {
        int linenum = 0;
        while (myfile)
        {
            if (myfile.eof())
                break;
            getline(myfile, mystring);
            for (int i = 0; i < mystring.size(); i++)
            {
                arr[linenum][i] = mystring[i] - 48;
                visible[linenum][i] = false;
            }
            linenum++;
        }
    }
    int numvisible = 0;
    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            if (i == 0 || i == 98 || j == 0 || j == 98)
            {
                visible[i][j] = true;
                numvisible++;
                continue;
            }
            bool treevisible = true;
            for (int k = 0; k < i; k++)
            {
                if (arr[k][j] >= arr[i][j])
                {
                    treevisible = false;
                    break;
                }
            }
            if (treevisible)
            {
                visible[i][j] = true;
                numvisible++;
                continue;
            }
            treevisible = true;
            for (int k = 98; k > i; k--)
            {
                if (arr[k][j] >= arr[i][j])
                {

                    treevisible = false;
                    break;
                }
            }
            if (treevisible)
            {
                visible[i][j] = true;
                numvisible++;
                continue;
            }
            treevisible = true;
            for (int k = 0; k < j; k++)
            {
                if (arr[i][k] >= arr[i][j])
                {

                    treevisible = false;
                    break;
                }
            }
            if (treevisible)
            {
                visible[i][j] = true;
                numvisible++;
                continue;
            }
            treevisible = true;
            for (int k = 98; k > j; k--)
            {
                if (arr[i][k] >= arr[i][j])
                {
                    treevisible = false;
                    break;
                }
            }
            if (treevisible)
            {
                visible[i][j] = true;
                numvisible++;
                continue;
            }
        }
    }
    cout << numvisible << endl;
}