#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
 
using namespace std;
 
int maxNum = 300;

bool matadj[300][300]; 

set <int> seen;

int main () {
    int ver, ed;
    cin >> ver >> ed;
    for(int i = 1; i <= ed; ++i) {
        int u, v;
        cin >> u >> v;
        matadj[v][u] = true;
        matadj[u][v] = true;
    }
    int j = 0;
    for(int i = 1; i <= ver; ++i) { 
        if(seen.find(i) == seen.end()){ 
            queue <int> q; 
            seen.insert(i);
            q.push(i);
            ++j;
            while(q.size()) {
                int x = q.front();
                q.pop();
                for(int i = 1; i <= ver; ++i) { 
                    if(matadj[i][x] && seen.find(i) == seen.end()) {
                        q.push(i);
                        seen.insert(i);
                    }
                }
            }
        }
    }
    cout << --j << '\n';
}