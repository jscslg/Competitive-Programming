#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);++i)
#define f_(i,a,b) for(ll i=(a);i>=(b);--i)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main() {
	fast;
	ll t;
	cin>>t;
	while(t--){
	    ll h,p;
	    cin>>h>>p;
	    int power=log2(p)+1;
	    ll res=2*p;
	    f(i,0,power){
	        if((1<<i)&p) res--;
	    }
	    //cout<<res<<" ";
	    cout<<(res>=h?1:0)<<endl;
	}
	return 0;
}
