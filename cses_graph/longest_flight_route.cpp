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
int n,m;
vvi g;
vi d,c,vis;

int dfs(int i){
    if(vis[i]) return d[i]+1;
    vis[i]=1;
    tr(e,g[i]){
        int res=dfs(e);
        if(d[i]<res){
            c[i]=e,d[i]=res;
        }
    }
    return d[i]+1;
}

void solve(){
    cin>>n>>m;
    g.assign(n,vi());
    d.assign(n,INT_MIN);
    c.assign(n,-1);
    vis.assign(n,0);
    d[n-1]=0;
    fr(i,0,m){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
    }
    int res=dfs(0);
    if(res<0) {
        cout<<"IMPOSSIBLE";
        return;
    } 
    cout<<res<<"\n";
    int i=0;
    while(i!=n-1){
        cout<<i+1<<" ";
        i=c[i];
    }
    cout<<n;
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