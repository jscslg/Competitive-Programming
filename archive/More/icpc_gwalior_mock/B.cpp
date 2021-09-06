/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using hmax=priority_queue<T>;
template<class T> using hmin=priority_queue<T,vector<T>,greater<T>>;
#define ll long long
#define ldb long double
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:(a))
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define ar(n) array<int,n>
#define ve vector
#define vi ve<int>
#define int ll
const int MOD = 1000000007, MOD2 = 998244353;
const int MAX=1e5;
ve<vi> g;
vi a,vis;
int res,c,n,m;

void rec(int v){
    vis[v]=c;
    tr(e,g[v]){
        if(!vis[e]) rec(e);
    }
}

void sol(){
    vi cur;
    fr(i,0,n) if(vis[i]==c) cur.pb(a[i]);
    sort(all(cur));
    fr(i,0,cur.size()/2) res+=cur[i]*2;
    if(cur.size()&1) res+=cur[cur.size()/2];
}

void solve(){
    cin>>n>>m;
    a=vi(n),vis=vi(n,0);
    tr(e,a) cin>>e;
    res=0,c=1;
    g=ve<vi>(n);
    fr(i,0,m){
        int x,y;cin>>x>>y,x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    fr(i,0,n){
        if(!vis[i]){
            rec(i);
            sol();
            c++;
        }
    }
    cout<<res<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
        auto start = chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifdef LOCAL_JUDGE
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cerr << "Time taken : " << duration.count() / 1000000.0 << "seconds"<< "\n";
    #endif
    return 0;
}