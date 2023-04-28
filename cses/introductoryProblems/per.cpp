#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    if(n == 1){
        cout << 1 << endl;
    }
    else if (n <= 3)
    {
        cout << "NO SOLUTION\n";
    }
    else if (n == 4)
    {
        cout << "2 4 1 3\n";
    }
    else
    {
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            cout << 2 * i + 1 << " ";
        }
        for (int i = 0; i < (n ) / 2; i++)
        {
            cout << 2 * i + 2 << " ";
        }
        cout << endl;
    }
    return 0;
}