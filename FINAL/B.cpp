#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
 
using namespace std;
 
int maxNum = 1e5;
int o[(int)1e5];

int main() {
    long long from, to;
    cin >> from >> to;
    queue<long long> que;
    que.push(from);
    map<int,int>vis;
    vis[from]=1;
    map <int,int> f;
    while(true) {
        long long temp=que.front();
        que.pop();
        if(temp == to) { 
            cout<<o[to] << endl; 
            vector <long long> ans; 
            while(temp != from ){ 
                ans.push_back(temp);
                temp = f[temp];
            }
            reverse(ans.begin(), ans.end()); 
            for(int x : ans)
                cout << x << ' ';
            break;
        }
        if(!vis[temp - 1] && temp > 1){ 
            vis[temp - 1] = 1; 
            o[temp - 1] = o[temp]+1; 
            que.push(temp - 1); 
            f[temp - 1] = temp; 
        }
        if(!vis[temp*2] &&temp*2<maxNum){ 
            vis[temp*2] = 1;
            o[temp*2] = o[temp]+1;
            que.push(temp*2);
            f[temp*2] =temp; 
        }
    }
}