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
//#define int ll
#define TR(i,a) for(auto& i:a)
#define F0(i,n) for(int i=0;i<(n);++i)
#define F1(i,n) for(int i=1;i<=(n);++i)
#define FO(i,a,b) for(int i=(a);i<(b);++i)
#define FR(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+4e3+1;

void solve(){
    int n,k;
    cin>>n>>k;
    vi a(n);
    TR(e,a) cin>>e;
    sort(all(a));
    vvi dp(n+1,vi(k,-1));
    int anum=n+1,asum=0,aindex=0,res;
    dp[0][0]=0;
    F0(i,n){
        F0(j,k){
            if(i && dp[i-1][j]!=-1) dp[i][j]=dp[i-1][j];
            if(dp[i][j]==-1) continue;
            int num=dp[i][j]+1,sum=j+a[i];
            if(sum>=k) {
                if(num<anum || (num==anum&&sum<asum)) anum=num,asum=sum,aindex=i; 
            }
            else dp[i+1][sum]=num;
        }
    }
     TR(e,dp) {
         TR(f,e) cout<<f<<" ";
         cout<<"\n";
    }
    cout<<anum<<" "<<asum<<" "<<aindex<<"\n";
    if(anum==n+1) {
        cout<<"-1\n";
        return;
    }
    vi f(n,0);
    int i=aindex;
    res=anum,asum-=a[i],anum--,f[i]=1,i--;
    while(anum>0){
        while(asum-a[i]<0 || asum-a[i]>=0 && dp[i][asum-a[i]]==-1) i--;
        f[i]=1,anum--,i--;
    }
    int sum=0,num=1;
    FR(j,n-1,0){
        if(f[i]) continue;
        sum+=a[i],num++;
        if(sum>=k){
            res+=num;
            break;
        }
    }
    if(sum<k) cout<<"-1\n";
    else cout<<res<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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