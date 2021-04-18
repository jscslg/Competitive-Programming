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
int n,m;
vvi g,g2;
vi vis,scc;
stack<int> s;

void dfs(int i){
    vis[i]=1;
    tr(e,g[i]) if(!vis[e]) dfs(e);
    s.push(i);
}
void dfs2(int i,int c){
    scc[i]=c;
    tr(e,g2[i]) if(!scc[e]) dfs2(e,c);
}

void solve(){
    cin>>n>>m;
    g.assign(n,vi());
    g2.assign(n,vi());
    vis.assign(n,0);
    scc.assign(n,0);
    fr(i,0,m){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
        g2[b].pb(a);
    }
    fr(i,0,n) if(!vis[i]) dfs(i);
    int c=1;
    while(!s.empty()){
        if(!scc[s.top()]) dfs2(s.top(),c++);
        s.pop();
    }
    cout<<c-1<<"\n";
    fr(i,0,n) cout<<scc[i]<<" ";
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