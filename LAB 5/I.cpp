#include <iostream> //OK
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
 
using namespace std;
 
void heapify(int arr[], int m, int i)
{
    int lar = i;
    int l = 2*i + 1; int r = 2*i + 2;
    if(l < m && arr[l] > arr[lar])
        lar = l;
    if(r < m && arr[r] > arr[lar])
        lar = r;
    if(lar != i)
    {
        swap(arr[i], arr[lar]);
        heapify(arr, m, lar);
    }
}



void heapsort(int arr[], int m)
{
    for(int i = m/2 - 1; i >= 0; i--)
        heapify(arr, m, i);
    for(int i = m - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print(int arr[], int m)
{
    for(int i = 0; i < m; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main()
{
    int m;
    cin >> m;
    int arr[m];
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    heapsort(arr, m);
    print(arr, m);
    return 0;
}