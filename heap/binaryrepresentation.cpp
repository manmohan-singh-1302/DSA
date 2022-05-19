/* a heap is a complete binary tree which is used to
solve any problems.

Key words in heap problems are: kth element and smallest or largest and sorting

heaps are of two types i.e:
1) max heap:
        priority_queue<int> maxh;
2) min heap:
        priority_queue(int,vector<int>, greater<int>) minh;

smallest element ----> max heap
largest element -----> min heap

*/

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