#include <bits/stdc++.h>
using namespace std;
void merge(int a[], int left, int mid, int right)
{
	int n2 = right - mid;			   // size of right array
	int n1 = mid - left + 1;		   // size of left array;
	int leftArray[n1], rightArray[n2]; // create two temp arrays to store values
	for (int i = 0; i < n1; i++)
		leftArray[i] = a[left + i];
	for (int j = 0; j < n2; j++)
		rightArray[j] = a[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) // merge left and right arrays into one
	{
		if (leftArray[i] <= rightArray[j])
		{
			a[k] = leftArray[i];
			i++;
		}
		else
		{
			a[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < n1) // checking if there arent any elements left
	{
		a[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < n2) // checking if there arent any elements left
	{
		a[k] = rightArray[j];
		j++;
		k++;
	}
}
void mergesort(int a[], int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergesort(a, begin, mid);
	mergesort(a, mid + 1, end);
	merge(a, begin, mid, end);
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mergesort(a, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}