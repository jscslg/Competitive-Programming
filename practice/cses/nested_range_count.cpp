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
#define vii ve<ar(2)>
#define viii ve<ar(3)>
//#define int ll
const int MOD = 1000000007, MOD2 = 998244353;
const int MAX=1e5;

void solve(){
    int n;
    cin>>n;
    viii a(n);
    fr(i,0,n) cin>>a[i][0]>>a[i][1],a[i][2]=i;
    viii b=a;
    oset<ar(2)> s,t;
    vi c(n),d(n);
    sort(all(a),[](ar(3) i,ar(3) j) {
        return i[0]<j[0] || (i[0]==j[0]&&i[1]>j[1]);
    });
    sort(all(b),[](ar(3) i,ar(3) j) {
        return i[1]<j[1] || (i[1]==j[1]&&i[0]>j[0]);
    });
    fr(i,0,n){
        c[a[i][2]]=i-s.order_of_key({a[i][1],-1});
        d[b[i][2]]=i-t.order_of_key({b[i][0],-1});
        s.insert({a[i][1],i});
        t.insert({b[i][0],i});
    }
    tr(e,d) cout<<(e?"1":"0")<<" ";
    cout<<"\n";
    tr(e,c) cout<<(e?"1":"0")<<" ";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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