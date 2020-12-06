#include <iostream> //OK
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
  
   
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  

    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  

    if (largest != i) { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 
  

void buildHeap(int arr[], int n) 
{  
    int startIdx = (n / 2) - 1; 
    for (int i = startIdx; i >= 0; i--) { 
        heapify(arr, n, i); 
    } 
} 
  

void printHeap(int arr[], int n) 
{ 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
    cout << endl; 
} 


int main() 
{ 
    int m;
    cin >> m;
    int size = 0;
    int arr[m];
    for(int i = 0; i < m; i++)
    { 
        cin >> arr[i];
        size++;
    }
    int n = size; 
  
    buildHeap(arr, n); 
    printHeap(arr, n); 
    return 0; 
} 