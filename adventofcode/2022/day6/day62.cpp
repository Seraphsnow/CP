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
    ifstream myfile("day6.txt");
    char mychar[14];
    ll score;
    if (myfile.is_open())
    {
        int i = 0;
        while (myfile)
        {
            i++;
            if (myfile.eof())
                break;
            if (i <= 14)
            {
                mychar[i - 1] = myfile.get();
            }
            else
            {
                char ch = myfile.get();
                bool notvalid = false;
                for(int k = 0; k < 14; k++){
                    for(int j = k+1; j<14; j++){
                        if(mychar[k] == mychar[j]){
                            notvalid = true;
                        }
                        if(notvalid) break;
                    }
                    if(notvalid) break;
                }
                if(!notvalid) break;
                else
                {
                    for(int j = 0; j<13; j++){
                        mychar[j] = mychar[j+1];
                    }
                    mychar[13] = ch;
                }
            }
        }
        cout << i-1 << endl;
    }
}