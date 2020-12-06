#include <iostream>
#include <queue>
#include <vector>
#include <string.h>

using namespace std;

vector< vector<int> > ans;
vector<int> comp;
vector<int> g[100000];
int n;
bool used[100000];

 
void dfs (int v)
{   used[v] = true;
    comp.push_back (v);
    for (size_t i=0; i<g[v].size(); i++)
    {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
}
 
void find_comps()
{
    vector<int> temp;
    for (int i=0; i<n; i++)
        used[i] = false;
    for (int i=0; i<n; i++)
    {
        temp.clear();
        if (! used[i])
        {
            comp.clear();
            dfs (i);
            for (size_t j=0; j<comp.size(); j++)
                temp.push_back( comp[j] );
            ans.push_back(temp);
        }
    }
}


int main()
{
    int m;
    cin >> n >> m;
    for (size_t i = 0; i < m; i++)
    {
        int x , y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    find_comps();
    
    cout << ans.size() << endl;
    
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i].size() << endl;
        for (size_t j = 0; j < ans[i].size(); j++)
        {
            cout << ++ans[i][j] << " ";
        }
        cout << endl;
    }
}