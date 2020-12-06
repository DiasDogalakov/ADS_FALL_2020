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
    string s;  ll cnt = 0;
    cin >> s;
    vector<ll> v = prefix_function(s);
    for (int i = 0; i < v.size(); i++)
        if (v[i] == 0)
            cnt++;
    ll k = s.size() - v[s.size() - 1];
    if(s.size() % k == 0)
        cout << s.size() / k;
    else
        cout << 1;
}