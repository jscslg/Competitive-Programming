#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,n)    for(ll (i)=0;(i)<n;(i)++)
#define f_(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define f_rev(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define in_num(n) ll n; cin>>n;
#define in_str(s) string s; cin>>s;
#define in_arr(x,n) ll x[n]; f(i,n) cin>>x[i];
#define fast ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);
using namespace std;

int main() {
	fast;
	in_num(t);
	f(i,t){
	    ll sum=0;
	    in_num(n);
	    in_arr(x,n);
	    f_(j,1,n){
	        sum+= (x[j]>x[j-1]?(x[j]-x[j-1])-1:x[j-1]-x[j]-1);
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
