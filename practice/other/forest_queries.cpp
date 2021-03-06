/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
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
int MAX=1e5+1;

void solve(){
    int n,q;
    cin>>n>>q;
    char a[n][n];
    fr(i,0,n) fr(j,0,n) cin>>a[i][j];
    vvi dp(n,vi(n,0));
    fr(i,0,n){
        int sum=0;
        fr(j,0,n){
            sum+=(a[i][j]=='*'?1:0);
            dp[i][j]+=sum;
            if(i==0) continue;
            dp[i][j]+=dp[i-1][j];
        }
    }
    while(q--){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2,x1--,x2--,y1--,y2--;
        cout<<dp[x2][y2]-(y1>0?dp[x2][y1-1]:0)-(x1>0?dp[x1-1][y2]:0)+(x1>0&&y1>0?dp[x1-1][y1-1]:0)<<endl;
    }
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