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
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
#define ii pair<int,int>
int MAX=1e5;

void solve(){
    int n;
    cin>>n;
    vi u(n),s(n);
    tr(e,u) cin>>e;
    tr(e,s) cin>>e;
    vector<vii> dp(n);
    fr(i,0,n) dp[u[i]-1].pb({s[i],s[i]});
    fr(i,0,n) sort(all(dp[i]),greater<ii>());
    sort(all(dp),[](vii &x,vii &y){
        return x.size()>y.size();
    });
    fr(i,0,n){
        fr(j,1,dp[i].size()){
            dp[i][j].S+=dp[i][j-1].S;
        }
    }
    //  fr(i,0,n+1){
    //      tr(e,dp[i]) cout<<e.F<<"x"<<e.S<<" ";
    //      cout<<"\n";
    // }
    fr(i,1,n+1){
        int l=0,sz,sum=0;
        while(l<n && dp[l].size()>=i){
            sz=dp[l].size();
            sum+=dp[l][sz-(sz%i)-1].S;
            l++;
        }
        cout<<sum<<" ";
    }
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