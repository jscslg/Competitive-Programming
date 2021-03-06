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
int MAX=1e5+1;

void solve(){
    int n;
    cin>>n;
    vector<char> s(n),o(n-1);
    tr(i,s) cin>>i;
    tr(i,o) cin>>i;
    vector<vii> dp(n,vii(n));
    fr(i,0,n) dp[i][i]={(s[i]=='T'?1:0),(s[i]=='F'?1:0)};
    fr(i,1,n){
        for(int j=0,k=i;k<n;j++,k++){
            ii e={0,0};
            for(int p=j,q=j+1;p<k && q<n;p++,q++){
                if(o[j]=='|'){
                    e.F+=dp[][].F+dp[][],e.S+=dp[][].S+dp[][].S;
                }
                else if(o[j]=='^'){
                    e.F+=min(dp[][].F,dp[][].S)+min(dp[][].S,dp[][].F);
                    e.S+=min(dp[][].F,dp[][].F)+min(dp[][].S,dp[][].S);
                }
                else{
                    e.F+=min(dp[])
                }
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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