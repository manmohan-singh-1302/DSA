#include<iostream>
#include<array>
using namespace std;
void rearrange(int arr[], int n){
    for(int i=0;i<n;i++){
        if(arr[i]!= -1 && arr[i]!=i){
            int x = arr[i];
            while(arr[x]!=-1 && arr[x]!=x){
                int y=arr[x];
                arr[x]=x;
                x=y;
            }
            arr[x]=x;
            if(arr[i]!=-1)
            arr[i]=-1;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    rearrange(arr,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}