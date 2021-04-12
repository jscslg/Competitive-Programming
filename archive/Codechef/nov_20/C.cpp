/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
#define int unsigned ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1,mod=(1ll<<32)-1;
vvi g;
vi p,sum,w;
map<ii,int> m;

void dfs(int v=0,int par=-1){
    p[v]=par;
    sum[v]+=w[v]*w[v],sum[v]&=mod;
    if(par!=-1) sum[v]+=sum[par],sum[v]&=mod;
    tr(e,g[v]){
        if(par==e) continue;
        dfs(e,v);
    }
}

int dot(int a,int b){
    int res=0,c=a,d=b;
    vi q(1,0);
    while(a!=b){
        if(m.find({max(a,b),min(a,b)})!=m.end()) {
            res=(res+m[{max(a,b),min(a,b)}])&mod;
            int temp=res,i=0;
            while(c!=a&&c!=b) {
                m[{max(c,d),min(c,d)}]=(res-q[i]+mod+1)&mod,i++;
                c=p[c],d=p[d];
            }
            return temp;
        }
        res=(res+w[a]*w[b])&mod;
        q.pb(res);
        a=p[a],b=p[b];
    }
    res=(res+sum[a])&mod;
    int temp=res,i=0;
    while(c!=d) {
        m[{max(c,d),min(c,d)}]=(res-q[i]+mod+1)&mod,i++;
        c=p[c],d=p[d];
    }
    return temp;
}

void solve(){
    int n,q;
    cin>>n>>q;
    g.resize(n,vi());
    p.resize(n);
    sum.resize(n,0);
    w.resize(n);
    tr(e,w) cin>>e;
    fr(i,0,n-1){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b),g[b].pb(a);
    }
    dfs();
    //tr(e,sum) cout<<e<<" ";
    while(q--){
        int a,b;
        cin>>a>>b,a--,b--;
        cout<<dot(a,b)<<"\n";
        //tr(e,m) cout<<e.F.F+1<<","<<e.F.S+1<<":"<<e.S<<" ";
        //cout<<endl;
    }
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