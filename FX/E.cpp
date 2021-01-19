#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <stack>
#include <algorithm>
 
using namespace std;
 
int main () {

    int n;
    cin >> n;
    vector <int> stone;

    for(int i = 0; i < n; ++i){
        int k;
        cin >> k;
        stone.push_back(k);
    }
    bool isgood = false;
    while(stone.size() != 0) {
        if(stone.size() == 1){
            cout << stone[0];
            isgood = 1;
            break;
        }

        sort(stone.begin(), stone.end());
        int x = stone[stone.size() - 1];
        stone.pop_back();
        int y = stone[stone.size() - 1];
        stone.pop_back();
        if(x != y)
            stone.push_back(x - y);
    }
    if(!isgood)
        cout << 0;

}