#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinHeap {
    public:
    vector<int> a;

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
        while (i > 0 && a[parent(i)] > a[i]) {
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

    int extractMin() {
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        if (a.size() > 0)
            heapify(0);
        return root;
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        while (i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    void print() {
        for (int i = 0; i < a.size(); i++) 
            cout << a[i] << " ";
        cout << endl;
    }

    int getMin() {
        return a[0];
    }
};

int main() {
    MinHeap *min_heap = new MinHeap();
    int n;
    cin >> n;
    int arr[n];
    vector<int> v;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    reverse(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        min_heap->insert(v[i]);
    }
    for(int i = 0; i < v.size(); i++)
    {
        min_heap->heapify(v[i]);
    }
    
    min_heap->print();
    return 0;
}