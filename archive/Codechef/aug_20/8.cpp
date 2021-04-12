#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(ll i=(a);i<(b);++i)
#define f_(i,a,b) for(ll i=(a);i>=(b);--i)
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 
vector<vector<int>> tree;
vector<int> p,a,b,res;
vector<bool> d;

void dfs(int x,int v,int pos,vector<bool>& f){
    f[x]=1;
    b[x]-=min(a[v],b[x]);
    if(b[x]==0 && res[x]==-1) res[x]=pos;
    f(i,0,tree[x].size()){
        if(!f[tree[x][i]]&&!d[tree[x][i]]) dfs(tree[x][i],v,pos,f);
    }
}

int main(){
    fast;
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        p.resize(n+1);
        a.resize(n+1);
        b.resize(n+1);
        d.resize(n+1);
        res.resize(n+1);
        tree.resize(n+1);
        f(i,1,n+1) {
            tree[i].clear();
            d[i]=0;
            res[i]=-1;
        }
        f(i,0,n-1){
            int u,v;
            cin>>u>>v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        f(i,1,n+1) cin>>p[i];
        f(i,1,n+1) cin>>a[i];
        f(i,1,n+1) cin>>b[i];
        f(i,1,n+1) {
            vector<bool> fl(n+1,0);
            dfs(p[i],p[i],i,fl);
            d[p[i]]=1;
            //f(j,1,n+1) cout<<b[j]<<" ";
        }
        f(i,1,n+1) cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}