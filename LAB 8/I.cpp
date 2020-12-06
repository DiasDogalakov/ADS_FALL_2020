#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

int d[101];
int start;
queue<int> q;
vector<int> g[101];
vector<int> a[1000];

void bfs(int v)
{
  for (int i = 0; i < 101; i++)
  {
    d[i] = -1;
  }
  
  q.push(v);
  d[v] = 0;
  a[start].push_back(v);
  while (q.empty() == false)
  {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++){
        int to = g[u][i];
        if (d[to] == -1){
            q.push(to);
            a[start].push_back(to);
            d[to] = d[u] +1;
        }
        }
  }
}


int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        for(int j = 0; j <n;j++){
        int x;
        cin >> x;
        if (x==1){
        g[i+1].push_back(j+1);
        g[j+1].push_back(i+1);
        }
        }
    }
    int end;
    cin >> start >> end;
    bfs(start);
    if(d[end]!=-1 and d[end]!=0){
        cout << d[end] << endl;
        for(int i=0; i < d[end]+1; i++){
            cout << a[start][i] << " ";
        }
    }
    else
        cout << d[end] << endl;
}