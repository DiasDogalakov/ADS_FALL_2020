#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
bool used[100][100];
char a[100][100];
int n, m;
int cnt;
int number;

void dfs(int i, int j){
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;
    if(a[i][j] == '.')
        return;
    if(used[i][j] == true)
        return;
    used[i][j] = true;
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i - 1, j);
    dfs(i, j + 1);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++)
            cin >> a[i][j];
    }
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if(used[i][j] == false && a[i][j] == '#')
            {
                dfs(i,j);
                number++;
            }
        }
    }
    cout << number << endl;
}