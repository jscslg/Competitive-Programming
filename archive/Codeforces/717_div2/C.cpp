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
int MAX=1e5;

void solve(){
    int n,s=0;
    cin>>n;
    vi a(n);
    tr(e,a) cin>>e,s+=e;
    if(s&1){
            cout<<"0";
            return;
        }
        s/=2;
        vvi dp(n+1,vi(s+1,0));
        fr(i,0,n+1) dp[i][0]=1;
        fr(j,1,n+1){
            fr(k,1,s+1){
                dp[j][k]=dp[j-1][k];
                if(k>=a[j-1] && dp[j-1][k-a[j-1]]) dp[j][k]=1; 
            }
        }
        if(dp[n][s]==0){
            cout<<"0";
            return;
        }
    fr(i,0,n){
        vi b;
        s=0;
        fr(j,0,n){
            if(j!=i) b.pb(a[j]),s+=a[j];
        }
        if(s&1){
            cout<<"1\n"<<i+1;
            return;
        }
        s/=2;
        dp = vvi(n,vi(s+1,0));
        fr(i,0,n) dp[i][0]=1;
        fr(j,1,n){
            fr(k,1,s+1){
                dp[j][k]=dp[j-1][k];
                if(k>=b[j-1] && dp[j-1][k-b[j-1]]) dp[j][k]=1; 
            }
        }
        if(dp[n-1][s]==0){
            cout<<"1\n"<<i+1;
            return;
        }
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