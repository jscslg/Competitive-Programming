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
#define int ll
int MAX=1e5;
vvi g;
vi vis,cyc;
stack<int> s;

bool checkCycle(int v){
    vis[v]=1;
    tr(e,g[v]){
        if(vis[e]==2) continue;
        if(vis[e] || checkCycle(e)) return 1;
    }
    vis[v]=2;
    return 0;
}

void dfs(int v){
    vis[v]=1;
    tr(e,g[v]){
        if(!vis[e]) dfs(e);
    }
    s.push(v);
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.assign(n,vi());
    vis.assign(n,0);
    fr(i,0,m){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
    }
    fr(i,0,n){
        if(!vis[i] && checkCycle(i)){
            cout<<"IMPOSSIBLE";
            return;
        }
    }
    vis.assign(n,0);
    fr(i,0,n){
        if(!vis[i]){
            dfs(i);
        } 
    }
    while(!s.empty()) {
        cout<<s.top()+1<<" ";
        s.pop();
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