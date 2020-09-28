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
    string str;
    int n;
    vector<pair<int, string> > v;
    while(cin >> str)
    {
        cin >> n;
        string s;
        cin >> s;
        
        
        v.push_back(make_pair(n, s));
    }
    stable_sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++)
    {
        cout << &v[i] << endl;
    }
    return 0;
}