#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);++i)
#define f_(i,a,b) for(ll i=(a);i>=(b);--i)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 
int n,C,k,m;
vector<ll> a,b,c,v,nc;

ll nc3(ll n){
    return (n*(n-1)*(n-2))/6;
}

ll solve(){
    vector<pair<ll,vector<ll>>> dp(k+1,{0,vector<ll>(nc.begin(),nc.end())});
    
    f(i,1,k+1){
        f(j,0,C){
            if(i>=v[j]){
                ll p=dp[i-v[j]].second[j];
                ll p2=(p>0)?((p-1)*(p-2))/2:0;
                //cout<<dp[i].first<<" x "<<(dp[i-v[j]].first+p2);
                if(dp[i].first<(dp[i-v[j]].first+p2)){
                    vector<ll> z=(dp[i-v[j]].second);
                    --z[j];
                    dp[i]={(dp[i-v[j]].first+p2),z};
                }
            }
        }
    }
    
    ll m=dp[0].first;
    f(i,1,k+1) m=max(m,dp[i].first);
    return m;
}

int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>C>>k;
        a.resize(n);
        b.resize(n);
        c.resize(n);
        v.resize(C);
        nc.clear();
        nc.resize(C,0);
        f(i,0,n) cin>>a[i]>>b[i]>>c[i];
        for(auto& i:v) cin>>i;
        f(i,0,n) nc[c[i]-1]++;
        ll m=0;
        f(i,0,C) m+=nc3(nc[i]);
        cout<<m-solve()<<endl;
    }
    return 0;
}