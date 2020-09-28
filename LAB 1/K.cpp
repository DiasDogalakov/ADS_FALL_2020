#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
            cnt++;
    }
    if(cnt == 0)
        cout << "prime";
    else
        cout << "composite";
    return 0;
}