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
//#define int ll
int MAX=1e5;
vi c,mc,sum;
vvi g;

int dfs(int v,int p=-1){
    int s=0,m=0,me;
    tr(e,g[v]){
        if(e!=p){
            int r=dfs(e,v);
            if(m<r) m=r,me=e;
            s+=r;
        }
    }
    mc[v]=me;
    return s+1;
}

set<int> dfs2(int v,int p=-1){
    set<int> res;
    tr(e,g[v]){
        if(e==mc[v]) res=dfs2(e,v);
    }
    tr(e,g[v]){
        if(e==p || e==mc[v]) continue;
        set<int> r=dfs2(e,v);
        res.insert(all(r));
    }
    res.insert(c[v]);
    sum[v]=res.size();
    return res;
}

void solve(){
    int n;
    cin>>n;
    c=vi(n);
    mc=vi(n);
    sum=vi(n);
    g=vvi(n);
    tr(e,c) cin>>e;
    fr(i,0,n-1){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    dfs2(0);
    tr(e,sum) cout<<e<<" ";
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