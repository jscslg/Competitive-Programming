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
#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<ii,vii,greater<ii>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1,n,m;

void solve(){
    cin>>n>>m;
    vector<vii> g(n);
    vi d(n,LLONG_MAX),f(n,0);
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        g[a].pb({b,c});
    }
    d[0]=0;
    hmin h;
    h.push({0,0});
    while(!h.empty()){
        int v=h.top().S,cd=h.top().F;
        h.pop();
        if (f[v]) continue;
        f[v]=1;
        tr(e,g[v]){
            if(!f[e.F]&&d[e.F]>d[v]+e.S){
                d[e.F]=d[v]+e.S;
                h.push({d[e.F],e.F});
            }
        }
    }
    tr(e,d) cout<<e<<" ";
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