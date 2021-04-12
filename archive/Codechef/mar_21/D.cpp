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
#define iii pair<ii,int>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
int MAX=1e5;

void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vi g(n+1);
    vector<iii> u(m,{{0,0},0});
    vector<vii> dp(n+1),ranges(n+1);
    dp[0].pb({0,0});
    fr(i,1,n+1) cin>>g[i];
    fr(i,0,m) {
        cin>>u[i].F.F>>u[i].F.S>>u[i].S;
        ranges[u[i].F.F].pb({i,u[i].S});
        ranges[u[i].F.S].pb({i,u[i].S});
    }
    //sort(all(u));
    fr(i,1,n+1){
        set<int> op,cl;
        int a=0,mk=0,f=0;
        vii tmp;
        tr(e,dp[i-1]) tmp.pb(e);
        frv(j,i,1){
            mk^=1LL<<j,a+=g[j];
            tr(e,ranges[j]){
                if(op.count(e.F)) a+=e.S;
                else op.insert(e.F);
            }
            if(j<=1) tmp.pb({a,mk});
            else tr(e,dp[j-2]) tmp.pb({e.F+a,mk^e.S});
        }
        sort(all(tmp));
        reverse(all(tmp));
        for(int j=0;j<tmp.size()&&f<k;j++){
            if(cl.count(tmp[j].S)>0) continue;
            f++,dp[i].pb(tmp[j]),cl.insert(tmp[j].S);
        }
    }
    fr(i,0,k) cout<<dp[n][i].F<<" ";
    cout<<"\n";
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