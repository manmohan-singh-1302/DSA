#include<bits/stdc++.h>
using namespace std;
void search(vector<int> arr, int element){
    int left = 0;
    int right = arr.size()-1;
    int pos = -1;
    for(left = 0; left<=right;){
        if(arr[left] == element){
            pos = left;
            cout<<"element found at"<<pos+1;
            break;
        }
        if(arr[right] == element){
            pos = right;
            cout<<"element found at "<<pos+1;
            break;
        }
        left++;
        right--;
    }
    if(pos==-1)
    cout<<"element not found";
}
int main(){
    vector<int> arr{1,2,3,4,5};
    int element = 4;
    search(arr,element);
}