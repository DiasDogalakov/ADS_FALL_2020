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
    long long a, b;
    cin >> a >> b;
    int c = min(a, b);
    long long gcd;
    vector<int> v;
    for(int i = 1; i <= c; i++)
    {
        v.push_back(i);
    }
    for(int i = 0; i < v.size(); i++)
    {
        if(a % v[i] == 0 && b % v[i] == 0)
            gcd = v[i];
    }
    cout << gcd << endl;
    return 0;
}