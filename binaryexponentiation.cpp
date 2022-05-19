#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int exp(ll a, ll b ){
    	ll res = 1;
	while(b!=0){
		if(b%2==0){
			a = ((a%mod)*(a%mod))%mod;
			b = floor(b/2);
		}
		else{
			res = ((res%mod)*(a%mod))%mod;
			b = b-1;
		}
	}
	return res;
}
int main(){
    ll a,b;
    cin>>a>>b;
    ll z = exp(a,b);
    cout<<z<<endl;
    return 0;
}