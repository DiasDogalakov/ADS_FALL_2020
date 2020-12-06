#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
 
using namespace std;

vector<int> ans;
vector<int> a;
vector<int> v;
class MinHeap {
    public:
    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        while (i > 0 && a[parent(i)] < a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        
        int j = left(i);
        if (right(i) < a.size() && a[right(i)] < a[left(i)])
            j = right(i);

        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    void top_priority(int A, int x)
    {
        for(int i = 0; i < a.size(); i++)
        {
            if(i+1 == A)
                a[i] += x;
        }
        heapify(A);
    }

    void insert_two(int k) {
        v.push_back(k);
        int i = v.size() - 1;
        while (i > 0 && v[parent(i)] < v[i]) {
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }

};

int main()
{
    MinHeap *min_heap = new MinHeap();
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        min_heap->insert(arr[i]);
    }
    int b;
    cin >> b;
    int cnt = 0;
    while(cnt < b)
    {
        cnt++;
        int A, x;
        cin >> A >> x;
        min_heap->top_priority(A, x);
    }
    for(int i = 0; i < a.size(); i++)
    {
        min_heap->heapify(i);
    }
    for(int i = 0; i < a.size(); i++)
    {
        min_heap->insert_two(a[i]);
    }
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
