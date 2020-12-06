#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
int main()
{
  int a[256][256]={0}, n, i, j, k, d, z, x, y, o;
 
  cin >> n;
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      cin >> a[i][j];
 
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      if(i!=j)
        for(k=0; k<n; k++)
          if(k!=j && k!=i && (d=a[i][j]+a[j][k]+a[k][i])<o)
            o=d, z=i, x=j, y=k;
            
    cout << x+1 << " " << y+1 << " " << z+1;
}