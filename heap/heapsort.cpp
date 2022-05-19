/* Time Complexity: Time complexity of heapify is O(Logn).
Time complexity of createAndBuildHeap() is O(n) and the overall
time complexity of Heap Sort is O(nLogn).*/

#include <bits/stdc++.h>
using namespace std;
void heapify(int a[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heap(int a[], int n)
{
    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
void prints(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    heap(a, n);
    prints(a, n);
    return 0;
}