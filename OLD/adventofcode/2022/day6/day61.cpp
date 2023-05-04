#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define fi first 
#define se second 
#define pb push_back 
#define pll pair<long long ,long long > 
#define ppll pair < pll , pll >

template <typename T>
void printArr(T*arr, ll size){
    cout << endl << endl;
    for(ll i = 0; i < size; i++){
        cout << i << ": " << arr[i] << endl;
    }
    cout << endl << endl;
}

vector<string> adv_tokenizer(string s, char del)
{
    stringstream ss(s);
    string word;
    vector<string> mystring;
    while (!ss.eof()) {
        getline(ss, word, del);
        mystring.pb(word);
    }
    return mystring;
}

int main(int argc, char*argv[]){
    ifstream myfile("day6.txt");
    char mychar[3];
    ll score;
    if(myfile.is_open()){
        int i = 0;
        while(myfile){
                        i++;
            if(myfile.eof()) break;
            if(i<=3){
                mychar[i-1] = myfile.get();
            }
            else{
                char ch = myfile.get();
                if(ch != mychar[0] && ch!=mychar[1] && ch!= mychar[2] && mychar[0] != mychar[1] && mychar[0] != mychar[2] && mychar[1] != mychar[2]){
                    break;
                }
                else{
                    mychar[0] = mychar[1];
                    mychar[1] = mychar[2];
                    mychar[2] = ch;
                }
            }

        }
        cout << i << endl;
    }
}