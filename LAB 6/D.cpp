    #include <iostream>
    #include <string>
    #include <vector>
    #include <set>
    #include <map>
    #include <cmath>

    using namespace std;
    
    vector<int> prefix_function (string& s)
    {
        int n = (int) s.length();
        vector<int> pi (n);
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

    vector<int> pref_function(string s) {
        int n = s.size();
        vector<int> pi(n);
        for (int i = 0; i < n; i++) {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
                j = pi[j - 1];
        }
    }

    int main()
    {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        string s;
        cin >> s;
        vector<int> p = prefix_function(s);
        for (int i = 0; i < s.size(); i++)
            cout << p[i] << " ";
        return 0;
    }