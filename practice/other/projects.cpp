//~~~JsCode~~~
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
const int MAX=1e5+1;

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n),p(n);
    map<ll,ll> m;
    fr(i,0,n){
        cin>>a[i]>>b[i]>>p[i],++b[i];
        m[a[i]],m[b[i]];
    }
    int cnt=0;
    tr(i,m) i.S=cnt++;
    vector<vector<ii>> pr(cnt);
    fr(i,0,n){
        pr[m[b[i]]].pb({m[a[i]],p[i]});
    }
    vi dp(cnt);
    fr(i,0,cnt){
        dp[i]=i>0?dp[i-1]:0;
        tr(e,pr[i]) dp[i]=max(dp[i],dp[e.F]+e.S);
    }
    cout<<dp[cnt-1];
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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