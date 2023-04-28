#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>

class Node
{
private:
    ll value;
    vector<Node *> dirsubords;

public:
    Node()
    {
        value = -1;
    }
    void addDirsubords(Node *subord)
    {
        dirsubords.pb(subord);
    }
    void findValue()
    {
        ll ans = 0;
        for (int i = 0; i < dirsubords.size(); i++)
        {
            ans += dirsubords[i]->getValue();
        }
        value = ans += dirsubords.size();
    }
    ll getValue()
    {
        if (value != -1)
            return value;
        else
        {
            this->findValue();
            return value;
        }
    }
};
int main(int argc, char *argv[])
{
    ll n;
    cin >> n;
    Node *arr[n];
    arr[0] = new Node();
    for (int i = 1; i < n; i++)
    {
        arr[i] = new Node();
    }
    for (int i = 1; i < n; i++)
    {
        //arr[i] = new Node();
        ll boss;
        cin >> boss;
        arr[boss - 1]->addDirsubords(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]->getValue() << " ";
    }
    cout << endl;
}