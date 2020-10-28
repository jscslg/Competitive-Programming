//~~~JsCode~~~
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
//#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
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
    int n,b=-1;
    cin>>n;
    vi a(n);
    tr(i,a) cin>>i;
    vii res;
    fr(i,1,n){
        if(a[i]!=a[0]) {
            res.pb({1,i+1});
            b=i;
        }
    }
    fr(i,1,n){
        if(a[i]==a[0]&&b!=-1) res.pb({b+1,i+1});
    }
    if(res.size()!=n-1) cout<<"NO\n";
    else {
        cout<<"YES\n";
        fr(i,0,n-1) cout<<res[i].F<<" "<<res[i].S<<endl;
    }
}  

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    fr(i,1,t+1){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}