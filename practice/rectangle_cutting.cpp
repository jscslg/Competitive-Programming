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
vvi dp;
int rec(int a,int b){
    if(a==b) dp[a][b]=1;
    if(dp[a][b]) return dp[a][b];
    int res=max(a,b);
    fr(i,1,a/2+1){
        res=min(res,rec(a-i,b)+rec(i,b));
    }
    fr(i,1,b/2+1){
        res=min(res,rec(a,b-i)+rec(a,i));
    }
    dp[a][b]=res;
    return res;
}

void solve(){
     int a,b;
     cin>>a>>b;
     dp.assign(a+1,vi(b+1,0));
     cout<<rec(a,b)-1;
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