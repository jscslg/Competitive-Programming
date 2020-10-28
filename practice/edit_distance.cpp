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
    string s1,s2;
    cin>>s1>>s2;
    int n1=s1.size(),n2=s2.size();
    vvi dp(n1+1,vi(n2+1,0));
    fr(i,0,n1+1) dp[i][0]=i;
    fr(i,1,n2+1) dp[0][i]=i;
    fr(i,1,n1+1){
        fr(j,1,n2+1){
            dp[i][j]=min(dp[i-1][j-1]+(s1[i-1]==s2[j-1]?0:1),min(dp[i-1][j]+1,dp[i][j-1]+1));
        }
    }
    cout<<dp[n1][n2];
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