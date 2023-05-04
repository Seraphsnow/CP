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
    ll scenicScore[99][99];
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
                scenicScore[linenum][i] = 1;
            }
            linenum++;
        }
    }
    int numvisible = 0, maxscenicScore = 0;;
    for (int i = 0; i < 99; i++)
    {
        for (int j = 0; j < 99; j++)
        {
            if (i == 0 || i == 98 || j == 0 || j == 98)
            {
                visible[i][j] = true;
                numvisible++;
                scenicScore[i][j] = 0;
                continue;
            }
            int left = i;
            for (int k = i-1; k >= 0; k--)
            {
                if (arr[k][j] >= arr[i][j])
                {
                    left = i-k;
                    break;
                }
            }
            scenicScore[i][j]*=left;
            int right = 98-i;
            for (int k = i+1; k <= 98; k++)
            {
                if (arr[k][j] >= arr[i][j])
                {
                    right = k-i;
                    break;
                }
            }
            scenicScore[i][j]*=right;
            int up = j;
            for (int k = j-1; k >= 0; k--)
            {
                if (arr[i][k] >= arr[i][j])
                {
                    up = j-k;
                    break;
                }
            }
            scenicScore[i][j]*=up;
            int down = 98-j;
            for (int k = j+1; k <= 98; k++)
            {
                if (arr[i][k] >= arr[i][j])
                {
                    down = k-j;
                    break;
                }
            }
            scenicScore[i][j]*=down;
            if(scenicScore[i][j]>maxscenicScore){
                maxscenicScore = scenicScore[i][j];
            }
        }
    }
    cout << maxscenicScore << endl;
}