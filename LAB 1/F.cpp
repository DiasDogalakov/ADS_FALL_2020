#include <iostream>
#include <stack>

using namespace std;

bool check(string str) {
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else {
            if (st.empty())
                return false;
            char ch = st.top();
            if (ch == '{' && str[i] != '}')
                return false;
            if (ch == '[' && str[i] != ']')
                return false;
            if (ch == '(' && str[i] != ')')
                return false;
            st.pop();
        } 
    }

    if (st.empty())
        return true;
    return false;
}

int main() {
    string str;
    cin >> str;
    if (check(str))
        cout << "yes";
    else
    {
        cout << "no";
    }
    return 0;
}