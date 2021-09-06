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

void solve(){
    int n,k,res=0;
    cin>>n>>k;
    vi a(n),f(n,LLONG_MIN);
    ve<ar(2)> b(n);
    tr(e,a) cin>>e;
    fr(i,0,n) b[i]={a[i],i};
    sort(all(b));
    fr(i,0,n-1) f[b[i][1]]=b[i+1][0];
    //tr(e,f) cout<<e<<" ";
    //cout<<"\n";
    int j=0;
    while(j<n){
        int c=1;
        j++;
        while(j<n && f[j-1]!=LLONG_MIN && a[j]==f[j-1]) j++,c++;
        res++;
        //if(c>1&&f[j]==LLONG_MIN) j++;
    }
    //cout<<res<<"x";
    if(k>=res){
        cout<<"Yes\n";
    } else cout<<"No\n";
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