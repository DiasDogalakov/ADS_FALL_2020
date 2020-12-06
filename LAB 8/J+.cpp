#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include<queue>
#define ll long long

using namespace std;

int main()
{
    int n;
    int x1, y1;
    int x2,y2;
    int u,v;
    int i, j;
    queue<pair<int, int> >q;
    int x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int y[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
    cin >> n;
    int d[n+1][n+1];
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            d[i][j]=1000000000;
    cin >> x1 >> y1 >> x2 >> y2;
    d[x1][y1] = 0; q.push(make_pair(x1,y1));
    while(!q.empty())
    {
        i = q.front().first;
        j = q.front().second;
        q.pop();
        for(int k = 0; k < 8; k++)
        {
            u = i + x[k];
            v = j + y[k];
            if(u > 0 && u <= n && v > 0 && v <= n && d[u][v] > d[i][j] + 1)
            {
                d[u][v] = d[i][j] + 1;
                q.push(make_pair(u,v));
            }
        }
    }
    cout << d[x2][y2] << endl;
    return 0;
}