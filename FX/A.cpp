#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <deque>
 
using namespace std;
 
int main () {
    deque <int> pl1, pl2;

    for(int i = 1; i <= 5; ++i){
        int x;
        cin >> x;
        pl1.push_back(x);
    }
    

    for(int i = 1; i <= 5; ++i){
        int x;
        cin >> x;
        pl2.push_back(x);
    }
    int win = 0;
    int h = 0;
    for(int i = 1; i <= 1000001; ++i) {
        if(pl1.size() == 0) {
            win = 2;
            h = i;
            break;
        }else if(pl2.size() == 0) {
            win = 1;
            h = i;
            break;
        }
        int f = pl1[0];
        int s = pl2[0];
        pl1.pop_front();
        pl2.pop_front();
        if(f == 0 && s == 9) {
            pl1.push_back(f);
            pl1.push_back(s);   
        }
        else if(f == 9 && s == 0) {
            pl2.push_back(f);
            pl2.push_back(s);
        }
        else if(f > s) {
            pl1.push_back(f);
            pl1.push_back(s);
        }else {
            pl2.push_back(f);
            pl2.push_back(s);
        }
    }
    --h;
    if(win == 1) {
        cout << "Boris " << h << '\n';
    }else if(win == 2) {
        cout << "Nursik " << h << '\n';
    }else {
        cout << "blin nichya" << '\n';
    }

}
