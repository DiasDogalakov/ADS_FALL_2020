#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque> 

using namespace std;
 
const int maxNum = 4e5;

int main ()  {
    string a;
    cin >> a;
    deque <char> d;
    int k = 0;
    while(k < a.size()) {
        int c = a[k];
        if(d.size()==0) {
            d.push_front(c);
        }else {
            if(d[d.size() - 1] == c) {
                d.pop_back();
            }else {
                d.push_back(c);
            }
        }
        ++k;
    }
    string ans = (d.size() == 0 ? "YES" : "NO");
    cout << ans;
    return 0;
}
