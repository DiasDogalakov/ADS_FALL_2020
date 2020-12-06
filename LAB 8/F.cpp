#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define ll long long

using namespace std;
 
vector<int> a[100];
queue<int> q;
int used[100];
int sw = 1;
int n, m, x, y;

void dfs(int  x,int t){
    int y;
    used[x] = t;
    for (int i = 0; i < a[x].size(); i++){
        y = a[x][i];
        if(used[y] == 0){
            dfs(y, 3-t);
        }
        else{
            if(used[y]==t){
                sw=0;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i =0; i < n ;i++){
        if (used[i]==0){
            dfs(i,1);
        }
    }
    if(sw==1){
        cout << "YES" << endl;
        for (int i=0 ; i < n ; i++){
            if (used[i]==1){
                cout << i+1 << " ";
            }
        }
    }
    else{
        cout << "NO";
    }
    return 0;
}