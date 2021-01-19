#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <stack>
 
using namespace std;
 
int m[200][200];
int vis[200];
int cnt = 0;
void dfs(int i, int v) {
    cnt = cnt + 1;
    vis[i] = 1;
    for(int j = 1; j <= v; ++j) {
        if(vis[j])
            continue;

        if(!m[i][j])
            continue;
        dfs(j, v); 
    }
}
int main (){
    int n, k;
    cin >> n >> k;
    int cntmore = 0;
    while(true) {
        int x;
        cin >> x;
        if(x == 0)
            break;
        
        int y;
        cin >> y;
        m[x][y] = 1;
    }
    dfs(k, n);
    if(cnt == n) {
        cout << "Yes";
    }else {
        cout << "No";
    }

}