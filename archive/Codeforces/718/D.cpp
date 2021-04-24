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
    int n,m,l;
    cin>>n>>m>>l;
    vvi lr(n,vi(m-1,0)),ud(n-1,vi(m,0));
    tr(e,lr) tr(i,e) cin>>i;
    tr(e,ud) tr(i,e) cin>>i;
    if(l&1){
        fr(i,0,n){
            fr(j,0,m) cout<<"-1 ";
            cout<<"\n";
        }
        return;
    }
    vector<vvi> dp(n,vvi(m,vi(l/2+1,0)));
    fr(i,1,l/2+1){
        fr(j,0,n){
            fr(k,0,m){
                dp[j][k][i]=INT_MAX;
                int x=j+1,y=k;
                if(x<n) dp[j][k][i]=min(dp[j][k][i],dp[x][y][i-1]+ud[j][k]);
                x=j-1,y=k;
                if(x>=0) dp[j][k][i]=min(dp[j][k][i],dp[x][y][i-1]+ud[x][k]);
                x=j,y=k+1;
                if(y<m) dp[j][k][i]=min(dp[j][k][i],dp[x][y][i-1]+lr[j][k]);
                x=j,y=k-1;
                if(y>=0) dp[j][k][i]=min(dp[j][k][i],dp[x][y][i-1]+lr[j][y]);
            }
        }
    }
    int x=l/2;
    fr(i,0,n){
        fr(j,0,m){ 
            //fr(k,0,l/2) 
            cout<<dp[i][j][x]*2<<" ";
            //cout<<"x";
        }
        cout<<"\n";
    }
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