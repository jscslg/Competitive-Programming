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
int MAX=1e5+1;

void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n);
    tr(e,a) cin>>e;
    vi nxt(MAX,n);
    vvi dp(n+1,vi(21,0));
    vi pr = vector<int>(MAX,1);
    for(int i=2;i*i<=MAX;i++){
        if(pr[i]==1){
            for(int j=i*i;j<=MAX;j+=i) if(pr[j]==1) pr[j]=i;
        }
    }
    fr(i,2,MAX+1) if(pr[i]==1) pr[i]=i;
    dp[n][0]=n;
    frv(i,n-1,0){
        dp[i][0]=dp[i+1][0];
        int t=a[i];
        while(t!=1){
            int e=pr[t];
            dp[i][0]=min(dp[i][0],nxt[e]);
            nxt[e]=i;
            while(t!=1&&e==pr[t]) t/=pr[t];
        }
    }
    fr(i,1,21){
        fr(j,0,n+1) dp[j][i]=dp[dp[j][i-1]][i-1];
    }
    while(q--){
        int l,r,y=0;
        cin>>l>>r,l--,r--;
        frv(i,20,0){
            if(dp[l][i]<=r) l=dp[l][i],y+=(1<<i);
        }
        cout<<y+1<<"\n";
    }
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