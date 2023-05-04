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
    ifstream myfile("day1.txt");
    string mystring;
    vector<ll> calories;
    if (myfile.is_open())
    {
        
        while(myfile){
            ll sum = 0;
            while(myfile){
                getline(myfile, mystring);
                if(mystring != ""){
                    sum += stoi(mystring);
                }
                else break;
            }
            calories.pb(sum);
        }
        calories[calories.end()-calories.begin()-1] -= 8445;
        sort(calories.begin(), calories.end(), greater<ll>());
        cout << calories[0] << endl;
        cout << calories[0]+calories[1]+calories[2] << endl;
    }

}