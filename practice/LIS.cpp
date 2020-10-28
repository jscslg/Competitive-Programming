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
    int n,j=0;
    cin>>n;
    vi a(n),p;
    tr(i,a) cin>>i;
    p.pb(a[0]);
    fr(i,1,n){
        if(a[i]>p[j]) p.pb(a[i]),++j;
        else{
            auto it=lower_bound(all(p),a[i]);
            *it=a[i];
        }
    }
    cout<<p.size();
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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