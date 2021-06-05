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
#define F first
#define S second
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
    vi a(4);
    tr(e,a) cin>>e;
    int m=a[0],mi=0,m2,mi2;
    fr(i,1,4){
        if(m<a[i]) m=a[i],mi=i;
    }
    if(mi==0) m2=a[1],mi2=1;
    else m2=a[0],mi2=0;
    fr(i,1,4){
        if(m2<a[i]&&i!=mi) m2=a[i],mi2=i;
    }
    mi++,mi2++;
    if((mi==1&&mi2==2)||(mi==2&&mi2==1)||(mi==3&&mi2==4)||(mi==4&&mi2==3)) cout<<"NO\n";
    else cout<<"YES\n";

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