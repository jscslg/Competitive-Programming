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
ll po(ll num,ll p=MOD-2){
    ll res=1;
    while(p>0){
        if(p&1) res=(res*num)%MOD;
        p>>=1,num=(num*num)%MOD;
    }
    return res;
}
void solve(){
    int n,s;
    cin>>n;
    s=(n*(n+1))/2;
    if(s%2) {
        cout<<0;return;
    }
    s/=2;
    vvi dp(2,vi(s+1,0));
    dp[0][0]=1,dp[1][0]=1;
    fr(i,0,n){
        int e=i+1;
        fr(j,1,s+1){
            dp[i%2][j]=dp[(i+1)%2][j];
            if(j>=e) dp[i%2][j]=(dp[i%2][j]+dp[(i+1)%2][j-e])%MOD;
        }
    }
    /*tr(i,dp) {
        tr(j,i) cout<<j<<" ";
        cout<<endl;
    }*/
    cout<<(dp[(n-1)%2][s]*po(2))%MOD;
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