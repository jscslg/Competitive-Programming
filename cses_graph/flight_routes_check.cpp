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

void dfs(int i,vvi &g,vi &v){
    v[i]=1;
    tr(e,g[i]){
        if(!v[e]) dfs(e,g,v);
    }
}

void solve(){
    cin>>n>>m;
    vvi g,g2;
    vi v1,v2;
    g.assign(n,vi());
    g2.assign(n,vi());
    v1.assign(n,0);
    v2.assign(n,0);
    fr(i,0,m){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
        g2[b].pb(a);
    }
    dfs(0,g,v1);
    dfs(0,g2,v2);
    fr(i,0,n){
        if(v1[i]&&v2[i]) continue;
        cout<<"NO\n";
        if(!v1[i]) cout<<"1 "<<i+1;
        else cout<<i+1<<" 1";
        return;
    }
    cout<<"YES";
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