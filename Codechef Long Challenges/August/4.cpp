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
	    string s,p;
	    cin>>s>>p;
	    vector<ll> a(26,0),b(26,0);
	    f(i,0,s.size()) a[s[i]-'a']++;
	    f(i,0,p.size()) b[p[i]-'a']++;
	    f(i,0,26) a[i]-=b[i];
	    int f=1;
	    f(i,1,p.size()){
	        if(p[i]>p[i-1]) {
	            f=2;
	            break;
	        }
	        else if(p[i]<p[i-1]) {
	            f=1;
	            break;
	        }
	    }
	    f(i,0,26){
	        char ch='a'+i;
	        if(ch==p[0]) if(f==1) cout<<p;
	        f(j,0,a[i]) cout<<ch;
	        if(ch==p[0]) if(f==2) cout<<p;
	    }
	    cout<<endl;
	}
	return 0;
}