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
    int n,k;
    cin>>n>>k;
    vi a(n);
    tr(e,a) cin>>e;
    sort(all(a));
    int m1=0,m2=0;
    m1=max(k-a[n-1],a[0]-1);
    m2=min(a[0]-1,k-a[n-1]);
    fr(i,0,n-1){
        int s=(a[i+1]-a[i])/2;
        if(s>m1) m2=m1,m1=s;
        else if(s>m2) m2=s; 
    }
    fr(i,0,n-1){
        if(a[i+1]-a[i]-1>m1+m2) m1=a[i+1]-a[i]-1,m2=0;
    }
    ldb res=(m1+m2)/(k*1.0);
    cout<<setprecision(8)<<fixed<<res<<"\n";
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
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}