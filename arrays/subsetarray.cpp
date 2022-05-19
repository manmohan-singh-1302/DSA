#include<bits/stdc++.h>
using namespace std;
string solve(int a[], int b[], int n, int m){
	set<int> s1;
	set<int> s2;
	for(int i=0;i<n;i++)
		s1.insert(a[i]);
	for(int j=0;j<m;j++)
		s2.insert(b[j]);
	for(auto i:s1){
		for(auto j:s2)
			if(s1.find(j) == s1.end())
				return "not a subset";
	}
	return "is a subset";
}
int main(){
	int n,m;
	cin>>n>>m;
	int a[n],b[m];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	cout<<solve(a,b,n,m);
	return 0;
}