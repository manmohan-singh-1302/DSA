#include<iostream>
using namespace std;
void binarysearch(int a[], int ele, int first, int last){
	int mid;
	mid = (first+last)/2;
	if(first>last)
		cout<<"element not found";
	else if(ele == a[mid])
		cout<<"element found";
	else if(ele>a[mid])
	binarysearch(a,ele,mid+1,last);
	else
	binarysearch(a,ele,first,mid-1);
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int ele;
	cin>>ele;
	binarysearch(arr,ele,0,n-1);
}