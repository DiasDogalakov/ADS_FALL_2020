#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
int main()
{
    int n, maxi, ans;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //bubble sort)
    for(int j = 0; j < n-1; j++)
    {
        for(int i = 0; i < a.size()-1; i++)
        {
            if(a[i] > a[i+1])
            {
                swap(a[i], a[i+1]);
            }
        }
    }
    for(int i = 0; i < a.size(); i++)
    {
        maxi = a[n-1];
        if(a[i] != maxi)
            ans = a[i];
    }
    cout << ans << endl;
    return 0;
}
