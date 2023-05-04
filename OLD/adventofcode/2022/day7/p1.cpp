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


class directory{
    private:
        string name;
        vector<pair<directory*,string>> subdirectories;
        vector<ll> files;
        directory* parent;
    public:
        directory(string name){
            this->name = name;
            parent = nullptr;
        }
        directory(string name, directory* parent){
            this->name = name;
            this->parent = parent;
        }
        
        void addPair(string name, directory* child){
            subdirectories.pb({child, name});
        } 
        void addFile(ll size){
            files.pb(size);
        }
        ll space(directory* mydir);
        directory* getparent(){
            return parent;
        }
        directory* child(string name){
            for(int i = 0; i < subdirectories.size(); i++){
                if(subdirectories[i].second == name) return subdirectories[i].first;
            }
            return nullptr;
        }
        string getname(){
            return name;
        }
};

map<directory*,ll> spacedict;

ll directory::space(directory* mydir){
            if(spacedict.find(mydir) != spacedict.end()){
                return spacedict[mydir];
            }
            ll totalspace = 0;
            for(int i = 0; i < files.size(); i++){
                totalspace+=files[i];
            }
            for(int i = 0; i < subdirectories.size(); i++){
                totalspace+=subdirectories[i].first->space(subdirectories[i].first);
            }
            spacedict[mydir] = totalspace;
            return totalspace;
        }

int main(int argc, char*argv[]){
    ifstream myfile("day7.txt");
    string mystring;
    ll score;
    directory* mydirectory = new directory("main", nullptr);
    directory* maindirectory = mydirectory;
    ll mysum = 0;
    if(myfile.is_open()){
        while(myfile){
            if(myfile.eof()) break;
            getline(myfile, mystring);
            vector<string> strings = adv_tokenizer(mystring, ' ');
            if(strings[0] == "$"){
                if(strings[1] == "cd"){
                    if(strings[2] == ".."){
                        mydirectory = mydirectory->getparent();
                    }
                    else if(strings[2] == "/"){
                        continue;
                    }
                    else{// directory name
                        mydirectory = mydirectory->child(strings[2]);
                    }
                }
                else{//ls hai
                    continue;
                }
            }
            else if(strings[0] == "dir"){
                directory* subdir = new directory(strings[1], mydirectory);
                mydirectory->addPair(strings[1], subdir);
            }
            else{
                mysum += stoi(strings[0]);
                mydirectory->addFile(stoi(strings[0]));
                cout << mysum << endl;
            }
        }
        maindirectory->space(maindirectory);
        map<directory*, ll>::iterator it;
        ll sum = 0;
        for(it = spacedict.begin(); it != spacedict.end(); it++){
            if(it->second<=100000) sum+= it->second;
        }
        cout << sum << endl;
    }
}