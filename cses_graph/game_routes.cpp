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
int n,m;
vi dp,vis;

int dfs(int v){
    vis[v]=1;
    tr(e,g[v]){
        if(!vis[e]) dfs(e);
        dp[v]+=dp[e];
        dp[v]%=MOD;
    } 
    return dp[v];
}

void solve(){
    cin>>n>>m;
    g.assign(n,vi());
    dp.assign(n,0);
    vis.assign(n,0);
    dp[n-1]=1;
    vis[n-1]=1;
    fr(i,0,m){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
    }
    cout<<dfs(0);
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