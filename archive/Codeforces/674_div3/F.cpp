#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<ll>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std; 

ll po(ll n,ll p=MOD-2){
    ll res=1;
    while(p>0){
        if(p&1) res=(res*n)%MOD;
        p>>=1;
        n=(n*n)%MOD;
    }
    return res;
}

void solve(){
    int n,cnt=0;
    string s;
    cin>>n>>s;
    vvi dp(n+1,vi(3,0));
    f(i,1,n+1){
        char c=s[i-1];
        if(c=='a') dp[i][0]+=po(3,cnt);
        else if(c=='b') dp[i][1]+=dp[i-1][0];
        else if(c=='c') dp[i][2]+=dp[i-1][1];
        else{
            dp[i][0]+=2*dp[i-1][0]+po(3,cnt);
            dp[i][1]+=2*dp[i-1][1]+dp[i-1][0];
            dp[i][2]+=2*dp[i-1][2]+dp[i-1][1];
            cnt++;
        }
        dp[i][0]=(dp[i][0]+dp[i-1][0])%MOD;
        dp[i][1]=(dp[i][1]+dp[i-1][1])%MOD;
        dp[i][2]=(dp[i][2]+dp[i-1][2])%MOD;
    }
    /*f(i,0,n+1){
        f(j,0,3) cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<dp[n][2]%MOD;
}

int main(){
    fast;
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}