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
int n,m,res=LLONG_MAX;
vector<vii> g,gr;

void solve(){
    cin>>n>>m;
    g.assign(n,vii());
    gr.assign(n,vii());
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        g[a].pb({b,c});
        gr[b].pb({a,c});
    }   
    vi dn(n,LLONG_MAX),d1(n,LLONG_MAX),f(n,0);
    hmin h;
    dn[n-1]=0;
    d1[0]=0;
    h.push({0,n-1});
    while(!h.empty()){
        int cd=h.top().F,v=h.top().S;
        h.pop();
        if(f[v]) continue;
        f[v]=1;
        tr(i,gr[v]){
            int e=i.F,c=i.S;
            if(!f[e] && dn[e]>dn[v]+c){
                dn[e]=dn[v]+c;
                h.push({dn[e],e});
            }
        }
    }
    f.assign(n,0);
    h.push({0,0});
    while(!h.empty()){
        int cd=h.top().F,v=h.top().S;
        h.pop();
        if(f[v]) continue;
        f[v]=1;
        tr(i,g[v]){
            int e=i.F,c=i.S;
            if(!f[e] && d1[e]>d1[v]+c){
                d1[e]=d1[v]+c;
                h.push({d1[e],e});
            }
        }
    }
    fr(i,0,n){
        tr(j,g[i]){
            int e=j.F,c=j.S;
            res= min(res,d1[i]+dn[e]+c/2);
        }
    }
    cout<<res;
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