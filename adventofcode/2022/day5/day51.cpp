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
    ifstream myfile("day5.txt");
    string mystring;
    vector<char> stacks[10];

    stacks[1].pb('B');
    stacks[1].pb('V');
    stacks[1].pb('S');
    stacks[1].pb('N');
    stacks[1].pb('T');
    stacks[1].pb('C');
    stacks[1].pb('H');
    stacks[1].pb('Q');

    stacks[2].pb('W');
    stacks[2].pb('D');
    stacks[2].pb('B');
    stacks[2].pb('G'); 

    stacks[3].pb('F');
    stacks[3].pb('W');   
    stacks[3].pb('R');   
    stacks[3].pb('T');
    stacks[3].pb('S');   
    stacks[3].pb('Q');   
    stacks[3].pb('B'); 

    stacks[4].pb('L');
    stacks[4].pb('G');   
    stacks[4].pb('W');   
    stacks[4].pb('S');   
    stacks[4].pb('Z');   
    stacks[4].pb('J');   
    stacks[4].pb('D');   
    stacks[4].pb('N');

    stacks[5].pb('M');   
    stacks[5].pb('P');   
    stacks[5].pb('D');   
    stacks[5].pb('V');   
    stacks[5].pb('F');

    stacks[6].pb('F');   
    stacks[6].pb('W');   
    stacks[6].pb('J');

    stacks[7].pb('L');   
    stacks[7].pb('N');   
    stacks[7].pb('Q');   
    stacks[7].pb('B');   
    stacks[7].pb('J');   
    stacks[7].pb('V');

    stacks[8].pb('G');   
    stacks[8].pb('T');   
    stacks[8].pb('R');   
    stacks[8].pb('C');   
    stacks[8].pb('J');   
    stacks[8].pb('Q');   
    stacks[8].pb('S');   
    stacks[8].pb('N'); 

    stacks[9].pb('J');   
    stacks[9].pb('S');   
    stacks[9].pb('Q');   
    stacks[9].pb('C');   
    stacks[9].pb('W');
    stacks[9].pb('D');   
    stacks[9].pb('M');   

    if(myfile.is_open()){
        while(myfile){
            if(myfile.eof()) break;
            getline(myfile, mystring);
            vector<string> strings = adv_tokenizer(mystring, ' ');
            ll num = stoi(strings[1]), from = stoi(strings[3]), to= stoi(strings[5]);
            for(int i = 0; i < num; i++){
                stacks[to].pb(stacks[from].back());
                stacks[from].pop_back();
            }
        }
        for(int i = 1; i < 10; i++){
            cout << stacks[i].back();
        }
        cout << endl;
    }
}