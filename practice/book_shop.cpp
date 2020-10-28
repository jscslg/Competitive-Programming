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
//#define int ll
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
    int n,x;
    cin>>n>>x;
    vi a(n),b(n);
    tr(i,a) cin>>i;
    tr(i,b) cin>>i;
    vvi dp(2,vi(x+1,0));
    fr(i,0,n){
        fr(j,0,x+1){
            if(j>=a[i]) dp[i%2][j]=max(dp[(i+1)%2][j],b[i]+dp[(i+1)%2][j-a[i]]);
            else dp[i%2][j]=dp[(i+1)%2][j];
        }
    }
    cout<<dp[(n-1)%2][x];
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