#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
bool used[100100];
vector<int> g[100100];
int ans = 0;
void dfs(int v){
   used[v] = true;
   ans++;
    for (int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(used[to] == false) dfs(to);
    }
}
int main(){
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j ++){
            int t;
            cin >> t;
            if (t == 1){
            x++; 
            g[i].push_back(j);
            }
        }
    }
    x /= 2;
    if (x != n - 1){
        cout << "NO" << endl;
        return 0;
    }
    dfs(1);
    if (ans != n){ 
        cout << "NO" << endl;
    }
    else{ 
        cout << "YES" << endl;
    }
}