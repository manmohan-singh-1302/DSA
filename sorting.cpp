#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mm 100001
#define mod 1000000007
ll ele(ll a,ll b){
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
ll palin(ll n){
    ll pal = n;
	ll ans = 0;
	if(n<10){
		ans = pal;
	}
	else {
		n /=10;
		while(n!=0){
			pal = pal*10+n%10;
			n/=10;
		}
		ans = pal;
	}
	return ans;
}
int main(){
	ll q;
	cin>>q;
	ll arr[mm] = {0};
	ll pre[mm] = {0};
	while(q--){
		ll l,r;
		cin>>l>>r;
		for(ll i=1;i<=mm;i++){
			arr[i] = palin(i);
			pre[i] = pre[i-1]+arr[i];
		}
		ll b = pre[r] - pre[l];
		ll z = ele(arr[l],b);
		cout<<z<<endl;
	}
	return 0;
}