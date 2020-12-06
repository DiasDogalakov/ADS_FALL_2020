#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define ll long long

using namespace std;

ll p = 31; ll p_pow[50001];

void power()
{
    p_pow[0] = 1;
    for(int i = 1; i < 50001; i++)
    {
        p_pow[i] = p_pow[i - 1] * p;
    }
}

ll hashing(string s)
{
    ll hash = 0;
    for(int i = 0; i < s.size(); i++)
    {
        hash += s[i] * p_pow[i];
    }
    return hash;
}

vector<ll> prefix(string s)
{
    vector<ll> h(s.size());
    h[0] = s[0];
    for(int i = 1; i < s.size(); i++)
    {
        h[i] = (s[i] * p_pow[i]) + h[i - 1];
    }
    return h;
}


int main()
{
    string s; string t; vector<ll> v;
    cin >> s >> t;
    power();
    ll hash_t = hashing(t);
    vector<ll> h = prefix(s);
    int n = s.size(); int m = t.size();

    for(int i = 0; i + m - 1 < n; i++)
    {
        int j = i + m - 1;
        ll hash_i_j = h[j];
        if(i)
            hash_i_j -= h[i - 1];
        if(hash_t * p_pow[i] == hash_i_j)
            v.push_back(i);
    }
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}
