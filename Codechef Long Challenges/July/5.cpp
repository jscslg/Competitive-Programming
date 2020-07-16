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
	    in_arr(a,n);
	    in_arr(b,n);
	    sort(a,a+n);
	    sort(b,b+n);
	    ll x[n],y[n];
	    ll p=0,q=0,r=0,s=0;
	    while(p!=n||q!=n){
	        if(a[p]==b[q]){
	            p++;
	            q++;
	        }
	        else if(a[p]>b[q]){
	            y[s++]=b[q++];
	        }
	        else {
	            x[r++]=a[p++];
	        }
	    }
	    while(p!=n){
	        x[r++]=a[p++];
	    }
	    while(q!=n){
	        y[s++]=b[q++];
	    }
	    if(r%2==0){
	        ll key[n];
	        bool flag=false;
	        ll k=0;
	        sort(x,x+r);
	        sort(y,y+s);
	        for(ll j=0;j<r;j+=2){
	            if(x[j]==x[j+1]){
	                key[k++]=x[j];
	            }
	            else flag=true;
	            if(y[j]==y[j+1]){
	                key[k++]=y[j];
	            }
	            else flag=true;
	        }
	        sort(key,key+k);
	        if(flag) cout<<-1<<endl;
	        else{
	            ll sum=0;
	            f(l,r/2){
	                if(2*a[0]<key[l]&&a[0]<=b[0]){
	                    sum+=(2*a[0]);
	                } 
	                else if(2*b[0]<key[l]&&a[0]>b[0]){
	                    sum+=(2*b[0]);
	                } 
	                else sum+=key[l];
	            }
	            cout<<sum<<endl;
	        }
	    }
	    else cout<<-1<<endl;
	}
	return 0;
}
