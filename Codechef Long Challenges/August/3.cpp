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
	    ll c,r;
	    cin>>c>>r;
	    ll a=((c-1)/9)+1,b=((r-1)/9)+1;
	    cout<<(b<=a?1:0)<<" "<<(b<=a?b:a)<<endl;
	}
	return 0;
}
