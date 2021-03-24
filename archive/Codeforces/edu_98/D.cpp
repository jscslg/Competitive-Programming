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
#define MOD 998244353
int MAX=1e5+1,n;
vi dp;
ll powm(ll num,ll p=MOD-2){
    ll res=1;
    while(p>0){
        if(p&1) res=(res*num)%MOD;
        p>>=1,num=(num*num)%MOD;
    }
    return res%MOD;
}

void solve(){
    int s=0;
    cin>>n;
    dp.assign(n,-1);
    dp[0]=1,dp[1]=1;
    for(int i=2;i<n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    }
    cout<<(powm(powm(2,n))*dp[n-1])%MOD;
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