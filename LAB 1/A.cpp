#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <stack>
 
using namespace std;
 
int main()
{
    stack<int> s;
    string str;
    bool check = true;
    vector<string> v;
    while(check == true)
    {
        cin >> str;
        if(str == "size")
        {
            int cur = s.size();
            char *
        }
        else if(str == "push")
        {
            int n;
            cin >> n;
            s.push(n);
            cout << "ok";
        }
        else if(str == "pop")
        {
            cout << s.top();
            s.pop();
        }
        else if(str == "back")
        {
            cout << s.top();
        }
        else if(str == "clear")
        {
            while(s.size() != 0)
                s.pop();
            cout << "ok";
        }
        else if(str == "exit")
        {
            check = false;
            cout << "bye";
        }
        cout << endl;
    }
}
