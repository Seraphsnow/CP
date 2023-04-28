#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

char asciitostring(ll n)
{
    return n + 65;
}

int main(int argc, char *argv[])
{
    string s;
    cin >> s;
    ll arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
        arr[s[i] - 65]++;
    }
    string ans = "";
    ll numodd = 0, odd = -1;
    
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] % 2)
        {
            numodd++;
            odd = i;
        }
    }
    if (numodd > 1)
    {
        cout << "NO SOLUTION\n";
    }
    else if (numodd == 1)
    {

        for (int j = 0; j < 26; j++)
        {
            if (j == odd)
                continue;
            for (int k = 0; k < arr[j] / 2; k++)
            {
                cout << asciitostring(j);
            }
        }
        for (int i = 0; i < arr[odd]; i++)
        {
            cout << asciitostring(odd);
        }
        for (int j = 25; j >= 0; j--)
        {
            if (j == odd)
                continue;
            for (int k = 0; k < arr[j] / 2; k++)
            {
                cout << asciitostring(j);
            }
        }
        cout << endl;
    }
    else
    {
        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < arr[j] / 2; k++)
            {
                cout << asciitostring(j);
            }
        }
        for (int j = 25; j >= 0; j--)
        {
            for (int k = 0; k < arr[j] / 2; k++)
            {
                cout << asciitostring(j);
            }
        }
        cout << endl;
    }
}