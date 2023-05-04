#include<bits/stdc++.h>
#include <string>

using namespace std;

int main(int argc, char*argv[]){
    int t;
    cin >> t;
    for(int i = 0; i < t ; i++){
        int n;
        char col;
        cin >> n >> col;
        string color;
        cin >> color;
        int mymin = 0;
        if(col == 'g') cout << "0\n";
        else{
            int firstG;
            for(int j = 0; j < n; j++){
                if(color[j] == 'g'){
                    firstG = j;
                    break;
                }
            }
            bool findg = false;
            int indexofsym;
            for(int k = 1; k <= n ; k++){
                if(!findg && color[(k+firstG)%n] == col){
                    indexofsym = k;
                    findg = !findg;
                }
                else if(findg && color[(k+firstG)%n] == 'g'){
                    mymin = max(mymin, k-indexofsym);
                    findg = !findg; 
                }
            }
            cout << mymin << endl;
        }
    }
}