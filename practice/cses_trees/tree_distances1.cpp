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
vi res;
vvi g,h;

int dfs(int v,int p=-1){
    int m=0,m1=0,m2=0,me=-1;
    tr(e,g[v]){
        if(e==p) continue;
        int r=dfs(e,v);
        if(r>m1) m2=m1,m1=r,me=e;
        else if(r>m2) m2=r;
        m=max(m,r);
    }
    h[v][0]=m1;
    h[v][1]=me;
    h[v][2]=m2;
    //cout<<v<<" "<<m1<<" "<<m2<<"\n";
    return m+1;
}

void dfs2(int v,int p=-1,int m=0){
    tr(e,g[v]){
        if(e==p) continue;
        int s=m;
        if(e==h[v][1]) s=max(s,h[v][2]);
        else s=max(s,h[v][0]);
        dfs2(e,v,s+1);
    }
    res[v]=max(m,h[v][0]);
}

void solve(){
    int n;
    cin>> n;
    g = vvi(n);
    h = vvi(n,vi(3));
    res = vi(n,0);
    fr(i,0,n-1){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    dfs2(0);
    tr(e,res) cout<<e<<" ";
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