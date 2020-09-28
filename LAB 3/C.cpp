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
    int maxi = -1001;
    int i_maxi;
    vector<int> v;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > maxi)
        {
            maxi = arr[i];
            i_maxi = i;
        }
    }
    //cout << maxi << " " << i_maxi << endl;
    cout << i_maxi + 1;
    return 0;
}
