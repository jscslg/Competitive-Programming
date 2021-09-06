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
    int n,m=INT_MAX,res=-1;
    cin>>n;
    vi a(n),b(n);
    tr(e,a) cin>>e;
    tr(e,b) cin>>e;
    vi x;
    fr(i,0,n) m=min((a[0]+b[i])%n,m);
    fr(i,0,n) if((a[0]+b[i])%n==m) x.pb(i);
    if(x.size()!=1){
        fr(i,0,n){
            int y=(a[i]+b[(x[0]+i)%n])%n;
            int y2=(a[i]+b[(x[1]+i)%n])%n;
            if(y2<y) {
                    res=x[1];
                    break;
                } else if(y<y2){
                    res=x[0];
                    break;
                }
        }
    } else res=x[0];
    if(res==-1) res=x[0];
    //cout<<res<<"x";
    fr(i,0,n){
        cout<<(a[i]+b[(res+i)%n])%n<<" ";
    }
    cout<<"\n";
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