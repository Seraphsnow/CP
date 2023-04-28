#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pll pair<ll,ll>

class mynode{
    private:
        ll n;
        mynode* next;
        mynode* prev;
    public:
        mynode(ll val){
            n = val;
            next = nullptr;
            prev = nullptr;
        }
        void setNext(mynode* node){
            next = node;
        }
        void setPrev(mynode* node){
            prev = node;
        }
        mynode* getNext(){
            return next;
        }
        mynode* getPrev(){
            return prev;
        }
        ll getn(){
            return n;
        }

};
int main(int argc, char*argv[]){
    ll n;
    cin >> n;
    mynode head(1);
    mynode* iter = &head;
    for(int i = 2; i <= n; i++){
        mynode* node;
        node = new mynode(i);
        iter->setNext(node);
        node->setPrev(iter);
        iter = node;
    }
    iter->setNext(&head);
    head.setPrev(iter);
    iter = &head;
    for(int i = 0; i < n; i++){
        cout << iter->getNext()->getn() << " ";
        iter->setNext(iter->getNext()->getNext());
        iter->getNext()->getNext()->setPrev(iter);
        iter = iter->getNext();
    }
    cout << endl;
}