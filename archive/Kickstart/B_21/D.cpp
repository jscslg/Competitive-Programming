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
vector<vector<iii>> g;
vi p;
vii a;

void dfs(int v,ii x,int par=-1){
    p[v]=par,a[v]=x;
    tr(e,g[v]){
        if(e.F!=par){
            dfs(e.F,e.S,v);
        }
    }
}

void solve(){
    int n,q;
    cin>>n>>q;
    g=vector<vector<iii>>(n);
    p=vi(n);
    a=vii(n);
    fr(i,0,n-1){
        int x,y,z,w;
        cin>>x>>y>>z>>w,x--,y--;
        g[x].pb({y,{z,w}});
        g[y].pb({x,{z,w}});
    }
    dfs(0,{0,0});
    vi qv(q),qw(q);
    fr(i,0,q){
        cin>>qv[i]>>qw[i],qv[i]--;
    }
    
    cout<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}