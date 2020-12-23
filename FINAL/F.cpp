#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
 
using namespace std;

const int maxNum = 2e5;
int mass[maxNum];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> mass[i];
    }
    vector<long long> h;
    h.push_back(mass[0]); 
    for(int i = 1; i <= n; ++i) 
        h.push_back(h[h.size()-1]+mass[i]); 
    sort(h.begin(), h.end());
    long long cnt = abs(mass[1]);
    for(int i = 1; i < h.size(); ++i)
        cnt = min(cnt, h[i] - h[i - 1]);
    cout << cnt <<endl;
    return 0;
}