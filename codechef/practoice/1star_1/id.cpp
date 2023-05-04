#include<bits/stdc++.h>
using namespace std;

int main(int argc, char*argv[]){
    int tl;
    cin >> tl;
    while(tl--){
        char s;
        cin >> s;
        if(s == 'b' or s == 'B') cout << "BattleShip\n";
        else if(s == 'c' or s == 'C') cout << "Cruiser\n";
        else if(s == 'd' or s == 'D') cout << "Destroyer\n";
        else cout << "Frigate\n";     
    }
}