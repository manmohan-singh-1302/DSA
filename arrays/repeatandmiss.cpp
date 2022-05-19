#include<iostream>
using namespace std;
void solve(int arr[], int n){
    int i ;
    cout<<"the repeating element is:";
    //iterate over the array and use the abs of evey element as the index and make the value of the index as negative i.e. mark as visited
  cout << " The repeating element is ";

    for (i = 0; i < n; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";
    }
    //to find the missing element iterate over the array to find the positive element
    cout << "and the missing element is ";
    for (i = 0; i < n; i++) {
        if (arr[i] > 0)
            cout << (i + 1);
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    solve(a,n);
}