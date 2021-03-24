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
vi f;

void dfs(int v,vi &f2,int par=-1){
    f[v]=1,f2.pb(v);
    tr(e,g[v]){
        if(e==par) continue;
        if(f[e]) {
            f2.pb(e);
            int i = (find(all(f2),e) - f2.begin());
            cout<<f2.size() - i<<"\n";
            while(i<f2.size()) cout<<f2[i++]+1<<" ";
            exit(0);
        }
        else dfs(e,f2,v);
    }
    f2.pop_back();
}

void solve(){
    int n,m;
    cin>>n>>m;
    g.assign(n,vi());
    f.assign(n,0);
    fr(i,0,m){
        int a,b;
        cin>>a>>b,--a,--b;
        g[a].pb(b),g[b].pb(a);
    }
    fr(i,0,n){
        if(!f[i]) {
            vi f2;
            dfs(i,f2);
        }
    }
    cout<<"IMPOSSIBLE";
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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