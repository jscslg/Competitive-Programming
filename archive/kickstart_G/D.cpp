#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define int ll
#define MOD 1000000007
#define fr(i,a) for(int i=0;i<(a);++i)
#define tr(i,a) for(auto& i:a)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define INIT 0
const int MAX=1e6;
void initialize(){}
int cnt,sum;
unordered_map<string,int> dp;
string tos(vi &a){
    string s;
    tr(i,a) s+=to_string(i)+'-';
    return s;
}

int rec(vi a,int sc=0){
    int n=a.size();
    string sa=tos(a);
    if(n==1) return sc;
    cout<<sa<<" ";
    if(dp[sa]!=0) return dp[sa];
    fr(i,n-1){
        vi b(n-1);
        for(int j=0;j<i;j++) b[j]=a[j];
        b[i]=a[i]+a[i+1];
        for(int j=i+2;j<n;j++) b[j-1]=a[j];
        string sb=tos(b);
        if(dp.find(sb)==dp.end()) dp[sb]=rec(b,sc+b[i]);
        dp[sa]+=dp[sb];
    }
    return dp[sa];
}

void solve(){
    int n;
    cin>>n;
    vi a(n);
    tr(i,a) cin>>i;
    cnt=0;
    sum=rec(a);
    ldb avg=(sum*1.0)/1;
    cout<<setprecision(10)<<fixed<<avg<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}