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
    int n,m,res=0;
    cin>>n>>m;
    vi a(n);
    tr(i,a) cin>>i;
    vii dp(n,{0,0});
    vvi dp2(n,vi(m,0));
    fr(i,0,n){
        if(a[i]==0){
            if(i==0) dp[i].F=1,dp[i].S=m;
            else dp[i].F=max(1ll,dp[i-1].F-1),dp[i].S=min(m,dp[i-1].S+1);
        }
        else dp[i].F=dp[i].S=a[i];
    }
    frv(i,n-2,0){
        if(a[i]==0) dp[i].F=max(dp[i].F,dp[i+1].F-1),dp[i].S=min(dp[i].S,dp[i+1].S+1);
    }
    fr(i,0,n){
        int l=dp[i].F,r=dp[i].S;
        fr(j,l-1,r){
            if(i==0) dp2[i][j]=1;
            else{
                if(j==0) dp2[i][j]=dp2[i-1][j]+dp2[i-1][j+1];
                else if(j==m-1) dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-1];
                else dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-1]+dp2[i-1][j+1];
            }
            dp2[i][j]%=MOD;
        }
    }
    fr(i,0,m) res=(res+dp2[n-1][i])%MOD;
    cout<<res<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    //cin>>t;
    fr(i,1,t+1){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}