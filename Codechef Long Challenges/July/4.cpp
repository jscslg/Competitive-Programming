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
    fast;
	in(t);
	f(i,t){
	    in(n);
	    n= 4*n-1;
	    ll x[n],y[n];
	    f(j,n){
	        in(a);
	        in(b);
	        x[j]=a;
	        y[j]=b;
	    }
	    sort(x,x+n);
	    sort(y,y+n);
	    ll p,q;
	    ll num=1;
	    f_(j,1,n){
	        if(x[j]==x[j-1]){
	            num++;
	        }
	        else {
	            if(num%2==1) {
	                p=x[j-1];
	                break;
	            }
	            else if(j==n-1){
	                p=x[j];
	                break;
	            }
	            num=1;
	        }
	    }
	    num=1;
	    f_(j,1,n){
	        if(y[j]==y[j-1]){
	            num++;
	        }
	        else {
	            if(num%2==1) {
	                q=y[j-1];
	                break;
	            }
	            else if(j==n-1){
	                q=y[j];
	                break;
	            }
	            num=1;
	        }
	    }
	    cout<<p<<" "<<q<<endl;
	}
	return 0;
}
