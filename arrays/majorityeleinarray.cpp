// C++ program to find Majority
// element in an array
#include <bits/stdc++.h>
using namespace std;

// Function to find Majority element
// in an array
// it returns -1 if there is no majority element

int majorityElement(int *arr, int n)
{
	// sort the array in O(nlogn)
	sort(arr, arr+n);
	
	int count = 1, max_ele = -1, temp = arr[0], ele, f=0;
	
	for(int i=1;i<n;i++)
	{
		// increases the count if the same element occurs
		// otherwise starts counting new element
		if(temp==arr[i])
		{
			count++;
		}
		else
		{
			count = 1;
			temp = arr[i];
		}
		
		// sets maximum count
		// and stores maximum occured element so far
		// if maximum count becomes greater than n/2
		// it breaks out setting the flag
		if(max_ele<count)
		{
			max_ele = count;
			ele = arr[i];
			
			if(max_ele>(n/2))
			{
				f = 1;
				break;
			}
		}
	}
	
	// returns maximum occured element
	// if there is no such element, returns -1
	return (f==1 ? ele : -1);
}


// Driver code
int main()
{
	int arr[] = {1, 1, 2, 1, 3, 5, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// Function calling
	cout<<majorityElement(arr, n);

	return 0;
}
