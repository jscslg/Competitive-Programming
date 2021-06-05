/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:(a))
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
int MAX=1e5,n;
vvi g,h;
vi l,r,p;

void dfs(int v,int par=-1,int ht=0){
    p[v]=par;
    h[ht].pb(v);
    tr(e,g[v]){
        if(e!=par){
            dfs(e,v,ht+1);
        }
    }
}

void solve(){
    cin>>n;
    g=vvi(n);
    h=vvi(n);
    l=vi(n);
    r=vi(n);
    p=vi(n);
    vii dp(n,{0,0});
    fr(i,0,n) cin>>l[i]>>r[i];
    fr(i,0,n-1){
        int x,y;
        cin>>x>>y,x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(0);
    int mh=0;
    fr(i,0,n) if(h[i].size()) mh=max(i,mh);
    frv(i,mh-1,0){
        tr(v,h[i]){
            int x=l[v],m=0;
            tr(e,g[v]){
                if(e!=p[v]) m+=max(dp[e].F+abs(x-l[e]),dp[e].S+abs(x-r[e]));
            }
            dp[v].F=m,x=r[v],m=0;
            tr(e,g[v]){
                if(e!=p[v]) m+=max(dp[e].F+abs(x-l[e]),dp[e].S+abs(x-r[e]));
            }
            dp[v].S=m;
        }
    }
    // fr(i,0,n){
    //     cout<<dp[i].F<<" "<<dp[i].S<<"\n";
    // }
    cout<<max(dp[0].F,dp[0].S)<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}