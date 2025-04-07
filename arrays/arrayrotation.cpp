
#include <iostream>

using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"asdfasdf";
    int count = 0;
    bool flag = true;
    int temp = 1;
    int sum = 0;
    while(true){
        int i;
        for(i=0;i<n;i++){
            if(temp%arr[i] == 0){
                break;
            }
        }
        if(i == n-1){
            sum+=temp;
            count++;
        }
        if(count>=k){
            flag = false;
        }
    }
    
    cout<<sum;
    return 0;
}