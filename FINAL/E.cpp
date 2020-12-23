#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include<queue>
 
using namespace std;
 
bool okbfs(int v, int md, int n, vector <int> &x, vector <int> &y) {
    queue <int> q;
    q.push(v);
    bool used[n];
    for(int i = 0; i < n; ++i)
        used[i] = 0;
    used[v] = 1;
    while(q.size()) {
        int cur = q.front();
        if(cur == n - 1)
            return 1;
        q.pop();
        for(int i = 0; i < n; ++i) {
            if(used[i] == 1)
                continue;
            if(abs(x[i] - x[cur]) + abs(y[i] - y[cur]) > md) {
                continue;
            }
            q.push(i);
            used[i] = 1;
        }
    }
    return false;
}

int main () {
    int n;
    cin >> n;
    vector <int> f, s;
    f = vector <int>(n);
    s = vector<int> (n);
    for(int i = 0; i < n; ++i)
        cin >> f[i] >> s[i];
    int left = 0, rgt = 1e9, answer = 1e9;
    while(left <= rgt) {
        int md = (left + rgt) / 2;
        if(okbfs(0, md, n, f, s)) {
            answer = md;
            rgt = md - 1; 
        }else {
            left = md + 1;
        }
    }
    cout << answer << '\n';
}