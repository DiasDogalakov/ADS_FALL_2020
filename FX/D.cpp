#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <stack>
 
using namespace std;
 
int main () {

    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        bool beautiful = true;
        stack <int> stack1;
        for(int j = 0; j < s.size(); ++j) {
            if(stack1.size() == 0 || stack1.top() != s[j])
                stack1.push(s[j]);
            else {
                stack1.pop();
            }
        }
        if(stack1.size() != 0)
            beautiful = 0;
        if(beautiful)
            cnt = cnt + 1;
    }
    cout << cnt;
}