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
    ifstream myfile("act.txt");
    string mystring;
    ll score;
    char arr[41][81];
    int visited[41][81];
    ll Sx, Sy, Ex, Ey;
    if (myfile.is_open())
    {
        ll linenum = 0;
        while (myfile)
        {
            if (myfile.eof())
                break;
            getline(myfile, mystring);
            for (ll i = 0; i < mystring.size(); i++)
            {
                if (mystring[i] == 'E')
                {
                    arr[linenum][i] = 'z';
                    Ex = linenum;
                    Ey = i;
                    visited[linenum][i] = -1;
                }
                else if (mystring[i] == 'S')
                {
                    arr[linenum][i] = 'a';
                    Sx = linenum;
                    Sy = i;
                    visited[linenum][i] = 0;
                }
                else
                {
                    arr[linenum][i] = mystring[i];
                    visited[linenum][i] = -1;
                }
            }
            linenum++;
        }
        vector<pll> bfs;
        bfs.pb({Sx, Sy});
        while (!bfs.empty())
        {
            pll elem = bfs.front();
            bfs.erase(bfs.begin());
            //cout << elem.fi << " " << elem.se << endl;
            
            int x, y;
            
            for (int i = 0; i < 4; i++)
            {
                if (i == 0)
                {
                    x = elem.fi;
                    y = elem.se - 1;
                }
                else if (i == 1)
                {
                    x = elem.fi + 1;
                    y = elem.se;
                }
                else if (i == 2)
                {
                    x = elem.fi;
                    y = elem.se + 1;
                }
                else
                {
                    x = elem.fi-1;
                    y = elem.se;
                }
                if (x >= 0 && y >= 0 && x <= 40 && y <= 80 && visited[x][y] == -1 && 
                (arr[x][y] == arr[elem.fi][elem.se] + 1 || arr[x][y] == arr[elem.fi][elem.se] || arr[x][y] < arr[elem.fi][elem.se]))
                {
                    if (x == Ex and y == Ey)
                    {
                        cout << visited[elem.fi][elem.se]+1 << endl;
                        return 0;
                    }
                    visited[x][y] = visited[elem.fi][elem.se] + 1;
                    bfs.pb({x, y});
                    //cout << visited[x][y] << endl;
                }
            }
        }
    }
}