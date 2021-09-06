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
//#define int ll
const int MOD = 1000000007, MOD2 = 998244353;
const int MAX=1e5;
int n,m;
vi dp,nxt;

vi ask(int i){
    cout<<"? "<<i+1<<endl;
    vi a(n);
    tr(e,a) cin>>e;
    return a;
}

int rec(vi& a,int i){
    if(dp[i]!=-1) return dp[i];
    if(i==m-1 || i==m-2){
        return dp[i];
    }
    int x=rec(a,i+1),y=rec(a,i+2);
    dp[i]=a[i]+min(x,y);
    if(x<y) nxt[i]=i+1;
    else nxt[i]=i+2;
    return dp[i];
}

void print(ve<vi>& g){
    ve<ar(2)> a;
    fr(i,0,n){
        tr(e,g[i]) a.pb({min(i,e)+1,max(i,e)+1});
    }
    sort(all(a));
    int i=0,n1=a.size();
    while(i<n1){
        ar(2) e=a[i];
        cout<<e[0]<<" "<<e[1]<<endl;
        while(e[0]==a[i][0]&&e[1]==a[i][1]) i++;
    }
}

void solve(){
    m=0;
    cin>>n;
    vi a = ask(0);
    ve<vi> f(n);
    ve<vi> g(n);
    fr(i,0,n) {
        m=max(m,a[i]);
        if(a[i]==1) g[0].pb(i);
        if(a[i]) f[a[i]-1].pb(i);
    }
    if(m==1) {
        cout<<"!"<<endl;
        print(g);
    }
    vi d(m,0);
    fr(i,0,n) if(a[i]) d[a[i]-1]++;
    dp=vi(m,-1);
    nxt=vi(m,-1);
    dp[m-1]=d[m-1],dp[m-2]=d[m-2];
    rec(d,0);
    //fr(i,0,m) cout<<dp[i]<<" ";
    //cout<<endl;
        int x;
        if(dp[0]<dp[1]) x=0;
        else x=1;
        while(x!=-1){
            tr(e,f[x]){
                vi b=ask(e);
                fr(i,0,n){
                    if(b[i]==1) g[e].pb(i);
                }
            }
            x=nxt[x];
        }
        cout<<"!"<<endl;
        print(g);
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    //INIT
    int t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}