#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<int> v2;
    int mini = 0;
    int maxi = 0;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        v.push_back(arr[i]);
        v2.push_back(arr[i]);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        mini = v[0];
        maxi = v[n-1];
    }
    
    //cout << mini << " " << maxi;

    for(int i = 0; i < v2.size(); i++)
    {
        if(v2[i] == maxi)
            cout << mini << " ";
        else
            cout << v2[i] << " ";
    }
    
    return 0;
}
