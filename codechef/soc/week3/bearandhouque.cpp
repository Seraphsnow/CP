#include <iostream>
using namespace std;

int main() {
    
    int ymin = 1, ymax = 2;
    bool between = false, found = false;
    while(true){
        cout << "? 0 " << ymax << endl;
        cout.flush();
        string s;
        cin >> s;
        if(s == "YES"){
            ymin = ymax;
            ymax = min(1000, ymax*2);
        }
        else{
            between = true; 
            break;
        }
        if(ymin == 1000){
            found = true;
            break;
        }
    }
    int y;
    if(!found){
        while(true){
            if(ymax == ymin){
                y = ymin;
                break;
            }
            int mid = (ymin+ymax)/2;
            if(ymin == mid){
                cout << "? 0 " << ymax << endl;
                cout.flush();
                string s;
                cin >> s;
                if(s == "YES"){
                    y = ymax;
                    break;
                }
                else{
                    y = ymin;
                    break;
                }
            }
            cout << "? 0 " << mid << endl;
            cout.flush();
            string s;
            cin >> s;
            if(s == "YES"){
                ymin = mid;
            }
            else{
                ymax = mid-1;
            }
        }
    }
    else{
        y = 1000;
    }
    
    
    
    int xmin = 1, xmax = 2;
    between = false; found = false;
    while(true){
        cout << "? " << xmax << " 0 " << endl;
        cout.flush();
        string s;
        cin >> s;
        if(s == "YES"){
            xmin = xmax;
            xmax = min(1000, xmax*2);
        }
        else{
            between = true; 
            break;
        }
        if(xmin == 1000){
            found = true;
            break;
        }
    }
    int x1;
    if(!found){
        while(true){
            if(xmax == xmin){
                x1 = xmin;
                break;
            }
            int mid = (xmin+xmax)/2;
            if(xmin == mid){
                cout << "? " << xmax << " 0 " << endl;
                cout.flush();
                string s;
                cin >> s;
                if(s == "YES"){
                    x1 = xmax;
                    break;
                }
                else{
                    x1 = xmin;
                    break;
                }
            }
            cout << "? " << mid << " 0 " << endl;
            cout.flush();
            string s;
            cin >> s;
            if(s == "YES"){
                xmin = mid;
            }
            else{
                xmax = mid-1;
            }
        }
    }
    else{
        x1 = 1000;
    }
    
    xmin = 1; xmax = 2;
    between = false; found = false;
    while(true){
        cout << "? " << xmax << " " << 2*x1 << endl;
        cout.flush();
        string s;
        cin >> s;
        if(s == "YES"){
            xmin = xmax;
            xmax = min(1000, xmax*2);
        }
        else{
            between = true; 
            break;
        }
        if(xmin == 1000){
            found = true;
            break;
        }
    }
    int x2;
    if(!found){
        while(true){
            if(xmax == xmin){
                x2 = xmin;
                break;
            }
            int mid = (xmin+xmax)/2;
            if(xmin == mid){
                cout << "? " << xmax << " " << 2*x1 << endl;
                cout.flush();
                string s;
                cin >> s;
                if(s == "YES"){
                    x2 = xmax;
                    break;
                }
                else{
                    x2 = xmin;
                    break;
                }
            }
            cout << "? " << mid << " " << 2*x1 << endl;
            cout.flush();
            string s;
            cin >> s;
            if(s == "YES"){
                xmin = mid;
            }
            else{
                xmax = mid-1;
            }
        }
    }
    else{
        x2 = 1000;
    }
    
    int ans = (4*x1*x1) + x2*(y-2*x1);
    cout << "! " << ans << endl;
	return 0;
}
