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
#define hmin priority_queue<ii,vector<ii>,greater<ii>>
#define MOD 1000000007
//#define int ll
int MAX=1e5;

void solve(){
    int n,m;
    cin>>n>>m;
    vvi a(n,vi(m)),res(n,vi(m,-1));
    vii b;
    vi in(n,m-1);
    fr(i,0,n) fr(j,0,m) cin>>a[i][j],b.pb({a[i][j],i});
    sort(all(b));
    fr(i,0,n) sort(all(a[i]));
    int x=0;
    fr(i,0,m){
        res[b[i].S][i]=b[i].F;
        fr(j,0,n){
            if(j!=b[i].S) res[j][i]=a[j][in[j]--];
        }
    }
    tr(e,res) {
        tr(i,e) cout<<i<<" ";
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
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}