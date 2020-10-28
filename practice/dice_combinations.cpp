#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
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
    int n,sum=0;
    cin>>n;
    vi dp(n+1,0);
    fr(i,1,n+1){
        if(i<=6) dp[i]=sum+1,sum+=dp[i];
        else dp[i]=sum,sum=sum-dp[i-6]+dp[i];
        sum=(sum+MOD)%MOD;
    }
    cout<<dp[n];
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    //INIT
    int t=1;
    //cin>>t;
    fr(i,1,t+1){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}