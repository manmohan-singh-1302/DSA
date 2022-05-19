#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int m;
	cin>>m;
	int a[m];
	for(int i=0;i<m;i++){
		cin>>a[i];
}
	vector<int> v;
	for(int i=0;i<n;i++){
		v.push_back(arr[i]);
	}
	for(int i=0;i<m;i++){
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	for(int it = 0;it<v.size();it++){
		cout<<v[it];
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		arr[i]=v[i];
	}
	for(int i=i+1;i<m;i++){
		a[i]=v[i];
	}
	for(int i=0;i<n;i++){
		cout<<arr[i];
	}
	cout<<endl;
	for(int i=0;i<m;i++){
		cout<<a[i]<<endl;
	}


	return 0;
}