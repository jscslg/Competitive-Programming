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

void solve(){
    int n,w,sum=0,res=0,ans=LLONG_MAX;
    cin>>n>>w;
    vi a(n);
    tr(i,a) cin>>i,sum+=i;
    int m=(ll)((ldb)sum*1.0/n+1.0/2);
    auto x=lower_bound(all(a),m),y=upper_bound(all(a),m);
    int med=(m-*x<*y-m)?*x:*y;
    res=0;
    tr(x,a) res+=min(abs(x-med),w+(-1*abs(med-x)));
    cout<<res<<endl;
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