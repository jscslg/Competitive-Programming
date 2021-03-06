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
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
int MAX=1e5;

void solve(){
    int n;
    cin>>n;
    vi a(n),b(n),pre(n);
    tr(e,a) cin>>e;
    tr(e,b) cin>>e;
    vvi dp(n,vi(n,0));
    fr(i,0,n) pre[i]=a[i]*b[i]+(i==0?0:pre[i-1]);
    fr(i,0,n) dp[i][i]=a[i]*b[i];
    fr(i,0,n-1) dp[i][i+1]=a[i]*b[i+1]+a[i+1]*b[i];
    for(int i=2;i<n;i+=2){
        for(int j=0,k=i;k<n;k++,j++){
            dp[j][k]=dp[j+1][k-1]+a[j]*b[k]+a[k]*b[j];
        }
    }
    for(int i=3;i<n;i+=2){
        for(int j=0,k=i;k<n;k++,j++){
            dp[j][k]=dp[j+1][k-1]+a[j]*b[k]+a[k]*b[j];
        }
    }
    int m=0;
    fr(i,1,n){
        for(int j=0,k=i;k<n;j++,k++){
            int x=dp[j][k]-(pre[k]-(j==0?0:pre[j-1]));
            if(m<x) m=x;
        }
    }
    cout<<pre[n-1]+m;
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