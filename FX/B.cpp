#include <iostream> //ok
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <deque>
 
using namespace std;
 
int main () {
    int n, h;
    cin >> n >> h;
    int a[n];
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int l = 1;
    int r = (int)1e9 + 1;
    int f = -1;

    while (l <= r) {
        int k = (l + r) / 2;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            int cur = a[i] / k; 
            if(a[i] % k != 0)
                cur ++;
            ans += cur;
        }
        if(ans <= h) {
            r = k - 1;
            f = k; 
        }else {
            l = k + 1;
        }
    }
    cout << f << '\n';
}