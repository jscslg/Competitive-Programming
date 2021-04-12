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
int n,q,cno=0;
vi comp,vis,p,cyc;
vvi g;

void dfs(int i,int c){
    comp[i]=c;
    vis[i]=1;
    tr(e,g[i]) {
        if(vis[e]==2) continue;
        if(!vis[e]) {
            p[e]=i;
            dfs(e,c);
        }
        else {
            cno++;
            int j=i;
            while(j!=e) cyc[j]=cno,j=p[j];
            cyc[j]=cno;
        }
    }
    vis[i]=2;
}

void solve(){
    vi t = vi(n);
    g = vvi(n,vi());
    cin>>n>>q;
    fr(i,0,n){
        cin>>t[i],t[i]--;
        g[i].pb(t[i]);
    }
    comp = vi(n,0);
    vis = vi(n,0);
    cyc = vi(n,0);
    int c=1;
    fr(i,0,n) if(!vis[i]) dfs(i,c++);
    
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