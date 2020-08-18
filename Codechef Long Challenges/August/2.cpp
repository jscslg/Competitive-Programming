#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);++i)
#define f_(i,a,b) for(ll i=(a);i>=(b);--i)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main() {
	fast;
	int t;
	cin>>t;
	while(t--){
	    ll n,k,min,m;
	    cin>>n>>k;
	    vector<ll> p(n);
	    for(auto& i:p) cin>>i;
	    m=-1;
	    f(i,0,n){
	        if(p[i]<=k&&k%p[i]==0){
	            if(m==-1) m=i;
	            else if(p[m]<p[i]) m=i;
	        }
	    }
	    cout<<(m==-1?-1:p[m])<<endl;
	}
	return 0;
}
