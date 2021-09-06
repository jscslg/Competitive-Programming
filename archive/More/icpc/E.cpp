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

void solve(){
    int n,m,ans=0;
    cin>>n>>m;
    vi a(n);
    tr(e,a) cin>>e;
    ve<vi> g;
    fr(i,0,m){
        int x,y;cin>>x>>y,x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    ve<vi> x;
    fr(i,0,n){
        vi p;
        x.pb(p);
    }
    hmin<ar(2)> h;
    fr(i,0,x.size()) h.push({x[i].size(),i});
    while(h.size()>1){
        vi y=x[h.top()];
        h.pop();
        vi z=x[h.top()];
        h.pop();
        ve<ar(2)> p,q;
        fr(i,0,y.size()) p.push_back({a[y[i]]});
        fr(i,0,z.size()) q.push_back({a[z[i]]});
        sort(all(y));
        sort(all(z));
        int i=0,j=0,res=INT_MAX,k,l;
        while(i<p.size()&&j<q.size()){
            if(res<abs(p[i][0]-q[i][0])) k=p[i][1],l=q[j][1],res=abs(p[i][0]-q[i][0]);
            res=min(res,abs(p[i][0]-q[j][0]));
            if(p[i]>q[j]) j++;
            else i++;
        }
        ans+=res;
        h.push({p.size()+q.size(),p});
    }

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