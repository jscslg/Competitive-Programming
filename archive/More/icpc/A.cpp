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
    int n;
    ll res=0;
    cin>>n;
    vi b;
    fr(i,0,n){
        int x;
        cin>>x;
        vi a(x),d;
        fr(j,0,x) cin>>a[j];

        int j=0;
        while(j<x){
            int c=1;
            j++;
            while(j<x&&a[j]>a[j-1]) c++,j++;
            d.push_back(c);
        }
        int l=0,r=d.size()-1;
        while(r>l){
            if(d[l]<d[r]) res+=d[l++];
            else res+=d[r--];
        }
        tr(e,d) b.pb(e);
    }
    //cout<<res<<"\n";
    //tr(e,b) cout<<e<<" ";
    //cout<<"\n";
    hmin<int> h;
    tr(e,b) h.push(e);
    while(h.size()>1){
        int y=h.top();
        h.pop();
        int z=h.top();
        h.pop();
        res+=y+z;
        h.push(y+z);
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