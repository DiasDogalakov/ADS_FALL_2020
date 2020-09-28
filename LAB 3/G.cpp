#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
bool b_search(int cur, vector<int> &a1)
{
    int l = 0;
    int r = a1.size()-1;
    while(l < r)
    {
        int m = (l + r) / 2;
        if(a1[m] == cur)
            return true;
        if(a1[m] > cur)
            r = m - 1;
        else
            l = m + 1;
    }
    if(a1[l] == cur)
        return true;
    return false;
}



int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a1(n);
    vector<int> a2(k);
    for(int i = 0; i < n; i++)
    {
        cin >> a1[i];
    }
    for(int j = 0; j < k; j++)
    {
        cin >> a2[j];
    }
    for(int j = 0; j < a2.size(); j++)
    {
        int cur = a2[j];
        if(b_search(cur, a1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
