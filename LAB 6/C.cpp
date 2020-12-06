#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define ll long long 

using namespace std;


vector<ll> prefix_function (string& s)
    {
        int n = (int) s.length();
        vector<ll> pi (n);
        for (int i=1; i<n; ++i)
        {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
            j = pi[j-1];
            if (s[i] == s[j])  ++j;
            pi[i] = j;
        }
        return pi;
    }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    string s1;
    string s2; 
    cin >> s1 >> s2;
    int ans = -1;
    str = s1 + "#" + s2 + s2;   
    vector<ll> v = prefix_function(str);
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] == s2.size())
            {
                ans = i - 2 * s1.size();
                break;
            }
        }    
       cout << ans;
}