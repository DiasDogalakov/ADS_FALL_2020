#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
int main()
{
    int i_of_element = 0;
    int n, x;
    int check = 0;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == x)
        {
            check += 1;
        }
    }
    if(check != 0)
    {
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == x)
                cout << i + 1 << " ";
        }

    }
    
    return 0;
}
