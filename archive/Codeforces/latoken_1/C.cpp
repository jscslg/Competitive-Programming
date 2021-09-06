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

ll powm(ll number,ll exponent=MOD-2){
    ll ret=1;
    while(exponent>0){
        if(exponent&1) ret=(ret*number)%MOD;
        exponent>>=1,number=(number*number)%MOD;
    }
    return ret;
}

void solve(){
    int n,x=1;
    cin>>n;
    vi a(n),b(n),c(n,0),d(n,0),e(n,0);
    fr(i,0,n) cin>>a[i],a[i]--,c[a[i]]=i;
    fr(i,0,n) cin>>b[i],b[i]--,d[b[i]]=i;
    fr(i,0,n){
        if(!e[i]){
            int y=d[a[i]];
            e[i]=x;
            while(!e[y]){
                e[y]=x,y=d[a[y]];
            }
            x++;
        }
    }
    //cout<<x<<"\n";
    cout<<powm(2,x-1)<<"\n";
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