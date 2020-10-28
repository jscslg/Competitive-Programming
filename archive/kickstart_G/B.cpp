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
    int n;
    cin>>n;
    vvi a(n,vi(n));
    fr(i,n) fr(j,n) cin>>a[i][j];
    vi sum(2*n-1,0);
    int x=0;
    fr(i,n){
        int j=i,k=0;
        while(j<n && k<n) sum[x]+=a[j][k],++j,++k;
        ++x;
    }
    for(int i=1;i<n;i++){
        int j=0,k=i;
        while(j<n && k<n) sum[x]+=a[j][k],++j,++k;
        ++x;
    }
    sort(all(sum),greater<int>());
    cout<<sum[0]<<endl;
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