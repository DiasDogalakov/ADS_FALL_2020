#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#define ll long long

using namespace std;
 
int main()
{
    int n;
    int s;
    cin >> n >> s;
    s--;
    int matrix[n][n];
    stack<int> st;
    int cnt=1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for(int j = 0; j < n; j++)
    {
        if(matrix[s][j] == 1){
              st.push(j);
        }
    }
    matrix[s][s]=1;
    while(!st.empty())
    {
        int a = st.top();
        st.pop();
        if(matrix[a][a] != 1)
        {
            for(int j = 0; j < n; j++)
                {
                    if(matrix[a][j] == 1){
                        st.push(j);
                    }
                }
            cnt++;
            matrix[a][a]=1;
        }
    }
    cout << cnt << endl;
    return 0;
}