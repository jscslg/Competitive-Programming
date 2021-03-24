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
//#define int ll
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
int MAX=1e5+1;
vvi g;
vi c,par,mark,down,dp;

void cycle(int u, int p, int& num){
    if (c[u] == 2) return;
    if (c[u] == 1) {
        num++;
        int cur = p;
        mark[cur] = num;
        while (cur != u) {
            cur = par[cur];
            mark[cur] = num;
        }
        return;
    }
    par[u] = p;
    c[u] = 1;
    for (int v : g[u]) {
        if (v == par[u]) continue;
        cycle(v, u, num);
    }
    c[u] = 2;
}

int dfs(int v=0,int p=-1){
    c[v]=1;
    tr(e,g[v]){
        if(e==p) continue;
        if(!c[v]) down[v]+=dfs(e)
    }
}

void solve(){
    int n,res=0;
    cin>>n;
    g.assign(n,vi());
    c.assign(n,0);
    down.assign(n,0);
    dp.assign(n,-1);
    par.resize(n);
    mark.resize(n);
    fr(i,0,n){
        int a,b;cin>>a>>b,a--,b--;
        g[a].pb(b);
        g[b].pb(a);
        par[i]=i,mark[i]=0;
    }
    int num=0;
    cycle(1,0,num);
    tr(e,mark) cout<<e<<" ";
    cout<<"\n";
    tr(e,par) cout<<e<<" ";
    cout<<"\n";
    int cy=0;
    tr(e,mark) if(e==1) cy++;
    res=(n*(n-1))/2+(cy*(cy-1))/2;
    c.assign(n,0);
    dfs();
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