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
#define hmax priority_queue<ii>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
int n,S,cnt,res,temp;
int ax[1000001],bx[1000001],con[1000001],a[100001],b[100001],vis[100001],par[100001],h[100001];
vi g[100001],currentSet;
hmax leafs;

void findLeafs(int v, int height){
    bool fl=0;
    h[v]=height,vis[v]=1;
    tr(e,g[v]){
        if(vis[e]) continue;
        fl=1,par[e]=v;
        findLeafs(e,height+1);
    }
    if(!fl) leafs.push({height,v});
}

void helper(int v){
    ax[a[v]]=0,bx[a[v]]=0,ax[b[v]]=0,bx[b[v]]=0,con[a[v]]=0,con[b[v]]=0;
}

int dfs(int v){
    vis[v]++,bx[b[v]]++,ax[a[v]]++,currentSet.pb(v);
    if(con[a[v]]==0) con[a[v]]++,temp++;
    else if(ax[a[v]]==bx[a[v]]) con[a[v]]--,temp--;
    if(con[b[v]]==0) con[b[v]]++,temp++;
    else if(ax[b[v]]==bx[b[v]]) con[b[v]]--,temp--;
    if(temp==0){
        if(v!=1 && vis[par[v]]==0){
            leafs.push({h[par[v]],par[v]});    
        }
        helper(v);
        return 1;
    }
    if(v!=1 && vis[par[v]]==0){
        if(dfs(par[v])==1){
            helper(v);
            return 1;
        }
    }
    helper(v);
    return 0;
}

void solve(){
    cin>>n>>S;
    fr(i,0,n-1){
        int x,y;  
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    fr(i,1,n+1) cin>>a[i];
    fr(i,1,n+1) cin>>b[i];
    // vi aa=a,bb=b;
    // sort(all(aa));
    // sort(all(bb));
    // fr(i,0,n) if(aa[i]!=bb[i]){
    //     cout<<"0\n";
    //     return;
    // }
    while(!leafs.empty()) leafs.pop();
    findLeafs(1,1);
    fr(i,0,n+1) vis[i]=0;
    bool flag=0;
    vvi all;
    while(!leafs.empty()){
        int v=leafs.top().S;
        leafs.pop();
        if(vis[v]) continue;
        temp=0,currentSet.clear();
        if(dfs(v)==0){
            flag=1;
            break;
        }
        else all.pb(currentSet);
    }
    if(flag){
        cout<<"0\n";
        return;
    }
    if(S==1){
        cout<<"1\n";
        return;
    }
    res=1;
    fr(i,0,all.size()){
        cnt=0;
        int u=all[i][0],l=u;
        fr(j,1,all[i].size()){
            if(h[u]>h[all[i][j]]) u=all[i][j];
            if(h[l]<h[all[i][j]]) l=all[i][j];
        }
        tr(e,g[l]){
            if(e==par[l]) continue;
            cnt++;
        }
        res*=(cnt+1),res%=MOD;
    }
    cout<<res<<"\n";
    fr(i,0,n+1) h[i]=0,vis[i]=0,par[i]=0,a[i]=0,b[i]=0,g[i].clear();
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