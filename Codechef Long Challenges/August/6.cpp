#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);++i)
#define f_(i,a,b) for(ll i=(a);i>=(b);--i)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> a(n),p(n,1);
        for(auto& i:a) cin>>i;
        f(i,1,n) p[i]=(p[i-1]*2)%MOD;
        f_(i,n-1,0) cout<<p[i]<<" ";
        cout<<endl;
    }
    return 0;
}
