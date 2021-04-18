/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
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
#define hmax priority_queue<ii>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
//#define int ll
int MAX=1e5;
vvi g;
vi h,p,vis;
hmax lf;
int res=0;

void dfs(int v,int par=-1,int ht=0){
    int f=0;
    h[v]=ht;
    p[v]=par;
    tr(e,g[v]){
        if(e!=par){
            dfs(e,v,ht+1);
            f=1;
        }
    }
    if(!f) lf.push({ht,v});
}

void solve(){
    int n;
    cin>>n;
    g = vvi(n);
    h = vi(n);
    p = vi(n);
    vis = vi(n,0);
    fr(i,0,n-1){
        int a,b;cin>>a>>b,a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    while(!lf.empty()){
        int v=lf.top().S;
        lf.pop();
        if(v==0) break;
        if(!vis[v] && !vis[p[v]]){
            vis[v]=1,vis[p[v]]=1,res++;
            int e=p[p[v]];
            if(e!=-1) lf.push({h[e],e});
        }
    }
    cout<<res;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}