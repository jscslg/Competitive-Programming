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

void print(string s,int k,int n){
    fr(i,0,k) cout<<s[i%n];
    cout<<"\n";
}

void solve(){
    int n,k,j=-1,mx;
    string s;
    cin>>n>>k>>s;
    char c=0;
    j=n;
    fr(i,1,n) {
        if(s[i]>s[0]) {
            j=i;
            break;
        }
    }
    n=j;
    vi a;
    fr(i,0,n) c=max(c,s[i]);
    fr(i,0,n) if(c==s[i]) a.pb(i);
    int n1=a.size();
    //tr(e,a) cout<<e<<" ";
    fr(i,0,n1-1){
        int k=i+1;
        int x=a[k]-a[i],y=((k==n1-1)?n:a[k+1])-a[k];
        int d=a[i],e=a[k];
        fr(l,0,y){
            if(s[d+l]<s[e+l]){
                mx=e;
                print(s,k,mx);
            }
            else if(s[d+l]>s[e+l]) break;
        }
    }
    print(s,k,n);
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
        auto start = chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    //cin>>t;
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