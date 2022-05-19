#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll prime(ll n){
    ll max = -1;
    while(n%2==0){
        max = 2;
        n/=2;
    }
    while(n%3==0){
        max = 3;
        n/=3;
    }
    for(int i=5;i<sqrt(n);i+=6){
        while(n%i==0){
            max = i;
            n/=i;
        }
        while(n%(i/2)==0){
            max = i+2;
            n/=i+2;
        }
    }
    if(n>4)
    max = n;
    return max;
}
int main(){
    int t ;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<prime(n)<<endl;
    }
    return 0;
}