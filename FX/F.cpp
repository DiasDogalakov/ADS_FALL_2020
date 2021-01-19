#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <stack>
 
using namespace std;
 
int vn = 1;
int to[(int)500000 + 10][26];
int cnt[(int)500000 + 10];
int find(deque <int> &t) { 
    int v = 1; 
    for (int i = 0; i < t.size(); i++) {
        char c = t[i] - 'a';
        if (to[v][c] == 0)
            return 0;
        v = to[v][c];
    }
    return cnt[v];
}
void add(string &s) {
    int v = 1;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i] - 'a'; 
        if (to[v][c] == 0) {
            to[v][c] = ++vn;
        }
        v = to[v][c];
        if(i == s.size() - 1)
            cnt[v]++;
    }
}
int main () {
    string s;
    cin >> s;
    int strs;
    cin >> strs;
    while(strs > 0) {
        string c;
        cin >> c;
        if(c != "")
            add(c);

        strs -= 1;
    }
    deque <int> ends;
    deque <int> starts;
    for(int i = 0; i < s.size(); ++i) 
        ends.push_back(s[i]);

    for(int i = 0; i < s.size(); ++i) {
        if(i == s.size() - 1)
            continue;
        starts.push_back(s[i]);
        ends.pop_front();
        if(find(starts) > 0 && find(ends) > 0) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    cout << '\n';
}