#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,n)    for(ll (i)=0;(i)<n;(i)++)
#define f_(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define f_rev(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define in(n) ll n; cin>>n;
#define in_str(s) string s; cin>>s;
#define in_arr(x,n) ll x[n]; f(i,n) cin>>x[i];
#define fast ios_base::sync_with_stdio(0);	cin.tie(0);	cout.tie(0);

using namespace std;

int main() {
	in(t);
	f(i,t){
	    in(n);
	    in(x);
	    in_arr(a,n);
	    sort(a,a+n);
	    ll sum=0;
	    f(j,n){
	        if(a[j]<=x/2){
	            sum++;
	        }
	        else if(a[j]<=x){
	            sum++;
	            x=a[j]*2;
	        }
	        else{
	            ll num= (a[j]-1)/x;
	            int p = (int)log2(num)+1;
	            sum+=(p+1);
	            x=a[j]*2;
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
