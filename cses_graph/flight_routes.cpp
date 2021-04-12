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
    int n,m,k;
    cin>>n>>m>>k;
    vector<vii> g(n,vii());
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        g[a].pb({b,c});
    }    
    hmin h;
    h.push({0,0});
    vi cnt(n,0),res;
    while(!h.empty() && cnt[n-1] < k){
        int v=h.top().S,c=h.top().F;
        h.pop();
        cnt[v]++;
        if(v==n-1) res.pb(c);
        if(cnt[v]>k) continue;
        tr(e,g[v]){
            h.push({c+e.S,e.F});
        }
    }
    tr(i,res) cout<<i<<" ";
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