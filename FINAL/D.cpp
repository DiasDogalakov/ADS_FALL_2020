#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
const int maxNum = 4e5;
int f[maxNum];

void h(string str) { 
    for (int j = 1;j<str.size();++j) {
        int leftPref=f[j-1];
        while (leftPref>0&&str[leftPref]!=str[j]) 
            leftPref=f[leftPref-1];
        if (str[leftPref]==str[j]) 
            leftPref++;
        f[j]=leftPref;
    }
}

int main(){
    string x, y;
    int n;
    cin>>n>>x;
    cin>>y;
    if(x.size() != y.size()){
        cout << "-1";
        return 0;
    }
    string ns = x+"|"+y+y;
    h(ns);
    bool found = false;
    int ans = -1;
    for(int i=0;i<maxNum;++i) {
        if(f[i]==n){
            ans=i;
            found=1;
            break;
        }
    }
    if(found) {
        ans-=n;
        ans-=n;
        cout<<ans; 
    }else {
        cout<<-1<<'\n';
    }
    return 0;
}