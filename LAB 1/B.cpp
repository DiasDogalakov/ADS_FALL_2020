#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
 
queue <int> q;
int n;
char str[102];

int main(){
    while (cin>>str)
    {
        if(strcmp(str,"push") == 0){
            cin>>n;
            q.push(n);
            cout<<"ok"<<endl;
        }
        else if(strcmp(str,"pop") == 0){
            if(q.size() == 0)
            {
                cout<<"error"<<endl;
            }
            else
            {
                cout<<q.front()<<endl;
                q.pop();
            }
        }
        else if(strcmp(str,"front") == 0){
            if(q.size() == 0)
            {
                cout<<"error"<<endl;
            }
            else                     
            {
                cout<<q.front()<<endl;
            }
        }
        else if(strcmp(str,"size") == 0){
            cout<<q.size()<<endl;
        }
        else if(strcmp(str,"clear") == 0){
            while (!q.empty())
            {
                q.pop();
            }
            cout<<"ok"<<endl; 
        }
         else if(strcmp(str,"exit") == 0){
            cout<<"bye"<<endl;
            break;
        }
    }
    
    return 0;
}