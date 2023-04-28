#include <bits/stdc++.h>
#include <limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll, ll>
int main(int argc, char *argv[])
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (x1 == x2)
        {
            if (y1 > y2)
            {
                if (x3 < x1)
                {
                    cout << "RIGHT\n";
                }
                else if (x3 == x1)
                {
                    cout << "TOUCH\n";
                }
                else
                {
                    cout << "LEFT\n";
                }
            }
            else
            {
                if (x3 > x1)
                {
                    cout << "RIGHT\n";
                }
                else if (x3 == x1)
                {
                    cout << "TOUCH\n";
                }
                else
                {
                    cout << "LEFT\n";
                }
            }
        }
        else if (x1 = x3)
        {
            if (y1 > y3)
            {
                if (x2 < x1)
                {
                    cout << "RIGHT\n";
                }
                else if (x2 == x1)
                {
                    cout << "TOUCH\n";
                }
                else
                {
                    cout << "LEFT\n";
                }
            }
            else
            {
                if (x2 > x1)
                {
                    cout << "RIGHT\n";
                }
                else if (x3 == x1)
                {
                    cout << "TOUCH\n";
                }
                else
                {
                    cout << "LEFT\n";
                }
            }
        }
        else{
            ld m12 = 1.0*(y2-y1)/(1.0*x2-1.0*x1), m13 = 1.0*(y3-y1)/(1.0*x3-1.0*x1); 
            if(m12 > 0){
                 
            }
        }
    }
}