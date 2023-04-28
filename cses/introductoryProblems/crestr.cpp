#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double

ll fact(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}

ll num(int *arr, int len)
{
    ll ans = fact(len);
    for (int i = 0; i < 26; i++)
    {
        ans /= fact(arr[i]);
    }
    return ans;
}

char numtochar(ll n){
    return n+97;
}

string* strings(int *arr, int len)
{   
    ll total = num(arr, len);
    if(len == 0){
        string* ans;
        ans = new string[1];
        ans[0] = "";
        return ans; 
    }
    string* ans;
    ans = new string[total];
    ll index = 0;
    for(int i = 0; i < 26; i++){
        if(arr[i]!=0){
            arr[i]--;
            string * substr = strings(arr, len-1);
            for(int j = 0; j < num(arr, len-1); j++){
                ans[index] = numtochar(i) + substr[j];
                //cout << ans[index] << endl;
                index++;
            }
            arr[i]++;
        }
    }
    return ans;
}

int main(int argc, char *argv[])
{
    string s;
    cin >> s;
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        arr[s[i] - 97]++;
    }
    ll ans = num(arr, s.size());
    cout << ans << endl;
    string* arr2;
    arr2 = new string[ans];
    arr2 = strings(arr, s.size());
    for(int i = 0; i < ans; i++){
        cout << arr2[i] << endl;
    }

    //cout << numtochar(0) << endl;
}