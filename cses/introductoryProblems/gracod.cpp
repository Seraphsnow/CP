#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

string *ans(int n)
{
    if (n == 1)
    {
        string* arr;
        arr = new string [2];
        arr[0] = "0";
        arr[1] = "1";
        return arr;
    }
    string *arr1 = ans(n - 1);
    int numelem = pow(2, n);
    string *arr2;
    arr2 = new string [numelem];
    for (int i = 0; i < numelem / 2; i++)
    {
        if (i % 2)
        {
            arr2[2 * i] = arr1[i] + "1";
            arr2[2 * i + 1] = arr1[i] + "0";
        }
        else
        {
            arr2[2 * i] = arr1[i] + "0";
            arr2[2 * i + 1] = arr1[i] + "1";
        }
    }
    return arr2;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;
    int power = pow(2, n);
    string* arr;
    arr = new string [power];
    arr = ans(n);
    for(int i = 0; i < power; i++){
        cout << arr[i] << endl;
    }
}