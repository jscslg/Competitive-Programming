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
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
int MAX=1e5;
int n;
vvi g;
vi d,ds,us;

int dfs(int v,int p=-1){
    int s=0,r=0;
    tr(e,g[v]){
        if(e==p) continue;
        int cur=dfs(e,v)+1;
        s+=cur,r+=cur+ds[e];
    }
    ds[v]=r;
    return d[v]=s;
}

void dfs2(int v,int p=-1,int s=0){
    int num=n-d[v]-1;
    us[v]=s+num;
    tr(e,g[v]){
        if(e==p) continue;
        dfs2(e,v,us[v]+ds[v]-ds[e]-d[e]-1);
    }
}

void solve(){
    cin>>n;
    g=vvi(n);
    d=vi(n,0);
    ds=vi(n,0);
    us=vi(n,0);
    fr(i,0,n-1){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    dfs2(0);
    fr(i,0,n) cout<<ds[i]+us[i]<<" ";
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