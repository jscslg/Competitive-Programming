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
vvi g;
vi h,p,c,res;

void dfs(int v,int par=0,int ht=0){
    h[v]=ht;
    p[v]=par;
    tr(e,g[v]){
        if(e==par) continue;
        dfs(e,v,ht+1);
    }
}

int dfs2(int v,int par=0){
    int cnt=0;
    tr(e,g[v]){
        if(e==par) continue;
        cnt+=dfs2(e,v);
    }
    return res[v]=cnt+c[v];
}

void solve(){
    int n,q;
    cin>>n>>q;
    p=vi(n,0);
    h=vi(n,0);
    c=vi(n,0);
    res=vi(n,0);
    g=vvi(n);
    fr(i,1,n){
        int a,b;cin>>a>>b,a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    vvi lca(n,vi(log2(n)+2,0));
    fr(i,0,n) lca[i][0]=p[i];
    fr(i,1,log2(n)+2){
        fr(j,0,n) {
            lca[j][i]=lca[lca[j][i-1]][i-1];
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b,a--,b--;
        int x=a,y=b;
        if(h[x]>h[y]){
            int k=h[x]-h[y],p=log2(k)+1;
            fr(i,0,p){
                if((1<<i)&k) x=lca[x][i];
            }
        }
        if(h[x]<h[y]){
            int k=-h[x]+h[y],p=log2(k)+1;
            fr(i,0,p){
                if((1<<i)&k) y=lca[y][i];
            }
        }
        if(x==y){
            if(h[a]<h[b]) c[b]++;
            else c[a]++;            
        }
        else {
            int p=log2(h[x])+1;
            frv(i,p,0){
                if(lca[x][i]!=lca[y][i]) x=lca[x][i],y=lca[y][i]; 
            } 
            x=lca[x][0];
            c[a]++,c[b]++;
            c[x]--;
        }
        if(x!=0) c[p[x]]--;
    }
    //tr(e,c) cout<<e<<" ";
    //cout<<"\n";
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