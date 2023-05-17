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

template <typename T>
void printVector(vector<T> arr)
{
    cout << endl
         << endl;
    for (ll i = 0; i < arr.size(); i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl
         << endl;
}

template <typename T>
T gcd(T a, T b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void adv_tokenizer(string s, char del) // Split string
{
    stringstream ss(s);
    string word;
    while (!ss.eof())
    {
        getline(ss, word, del);
        cout << word << endl;
    }
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n, q;
    cin >> n >> q;
    set<int> cols[n+1], rows[n + 1];
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x, y;
            cin >> x >> y;
            cols[x].insert(y);
            rows[y].insert(x);
        }
        else if (t == 2)
        {
            int x, y;
            cin >> x >> y;
            cols[x].erase(cols[x].find(y));
            rows[y].erase(rows[y].find(x));
        }
        else{
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool done = true;
            for(int j = x1; j <=x2; j++){
                if(!cols[j].size()){
                    done = false;
                    break;
                }
            }
            if(done){
                cout << "YES\n";
                continue;
            }
            done = true;
            for(int j = y1; j <=y2; j++){
                if(!rows[j].size()){
                    done = false;
                    break;
                }
            }
            if(done){
                cout << "YES\n";
                continue;
            }
            else{
                cout << "NO\n";
            }
        }
    }
}