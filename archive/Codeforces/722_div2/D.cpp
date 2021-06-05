/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update>
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
#define MOD 998244353
#define int ll
int MAX=1e6;
vi pr,dp;

ll powm(ll number,ll exponent=MOD-2){
    ll ret=1;
    while(exponent>0){
        if(exponent&1) ret=(ret*number)%MOD;
        exponent>>=1,number=(number*number)%MOD;
    }
    return ret;
}

void solve(){
    int n;
    cin>>n;
    cout<<dp[n]<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    pr = vector<int>(MAX+1,1);
    for(int i=2;i*i<=MAX;i++){
        if(pr[i]==1){
            for(int j=i*i;j<=MAX;j+=i) if(pr[j]==1) pr[j]=i;
        }
    }
    for(int i=2;i<=MAX;i++) if(pr[i]==1) pr[i]=i;
    dp = vi(MAX+1,0);
    dp[1]=1;
    int pre=1;
    fr(i,2,MAX+1){
        int x=i,div=1;
        while(x>1){
            int c=0,cur=pr[x];
            while(cur==pr[x]) x/=cur,c++;
            div=(div*(c+1))%MOD;
        }
        dp[i]=(dp[i]+div)%MOD;
    }
    fr(i,2,MAX+1){
        dp[i]=(dp[i]+pre)%MOD;
        pre=(pre+dp[i])%MOD;
    }
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}