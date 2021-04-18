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
#define hmin priority_queue<ii,vii,greater<ii>>
#define MOD 1000000007
#define int ll
int MAX=1e5;

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vii> g(n,vii());
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        g[a].pb({b,c});
    }
    hmin h;
    h.push({0,0});
    vi fmax(n,0),fmin(n,0),num(n,0),vis(n,0),dis(n,LLONG_MAX);
    num[0]=1;dis[0]=0;
    while(!h.empty()){
        int c,v;
        tie(c,v)=h.top();
        h.pop();
        if(vis[v]) continue;
        vis[v]=1;
        tr(i,g[v]){
            int e=i.F,cd=i.S,cur=cd+c;
            if(cur==dis[e]){
                num[e]+=num[v],num[e]%=MOD;
                fmax[e]=max(fmax[v]+1,fmax[e]);
                fmin[e]=min(fmin[v]+1,fmin[e]);
                h.push({cur,e});
            }
            else if(cur<dis[e]){
                dis[e]=cur;
                num[e]=num[v];
                fmax[e]=fmax[v]+1;
                fmin[e]=fmin[v]+1;
                h.push({cur,e});
            }
        }
    }
    cout<<dis[n-1]<<" "<<num[n-1]<<" "<<fmin[n-1]<<" "<<fmax[n-1];
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