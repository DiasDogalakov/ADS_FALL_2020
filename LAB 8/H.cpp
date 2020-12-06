#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#define ll long long

using namespace std;
 
int NEW = 0;
int to = 1;
int q = 2;
int n,m;
bool used[123];
vector<int> g[123];
vector<int> k(123, NEW);
vector<int> path;

void dfs (int v){
    if (k[v] == to){
        cout << "No" << endl;
        exit(0);
    }
    if (k[v] == q){
        return;
    }
    k[v] = to;
    for (int i = 0; i < g[v].size(); ++i){
        int to = g[v][i];
        dfs(to);
    }
    k[v] = q;
    path.push_back(v);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i ++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i ++){
        if (k[i] == NEW) dfs(i);
    }
    cout << "Yes" << endl;
    reverse(path.begin(), path.end());
    for (auto i : path){
        cout << i + 1 << " ";
    }
    return 0;
}