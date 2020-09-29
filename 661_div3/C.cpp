#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);i++)
#define f_(i,a,b) for(ll i=(a);i>=(b);i--)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<ll> dp(n,-1),a(n,-1),b(n,-1);
        ll l,max=0,x=-1,y=-1;
        f(i,0,n){
            if(s[i]=='1') {
                if(x!=-1) l=a[x--],b[++y]=l;
                else l=(++max),b[++y]=l;
            }
            if(s[i]=='0'){
                if(y!=-1) l=b[y--],a[++x]=l;
                else l=(++max),a[++x]=l;
            }
            dp[i]=l;
        }
        cout<<max<<endl;
        f(i,0,n) cout<<dp[i]<<" ";
        cout<<endl;
    }
}