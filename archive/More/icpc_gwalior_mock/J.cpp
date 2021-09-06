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
    cin>>n;
    ve<ar(2)> a(n);
    vi res(n);
    fr(i,0,n) {
        int x;cin>>x;
        a[i]={x,i};
    }
    sort(all(a));
    int i=0;
    while(i<n){
        int x=0,cur=a[i][0],j=i,y;
        while(i<n && a[i][0]==cur) x++,i++;
        
        if(x==1) y = min(j,n-i)*2+1;
        else if(x&1) {
            int l=j,r=n-i;
            if(r>l) {
                int t=min(r-l,x-1);
                l+=t,x-=t;
            }
            else {
                int t=min(l-r,x-1);
                r+=t,x-=t;
            }
            y = (min(l,r)+(x-1)/2)*2+1;
        }
        else{
            int l=j,r=n-i;
            if(r>l) {
                int t=min(r-l,x-1);
                l+=t,x-=t;
            }
            else {
                int t=min(l-r,x-1);
                r+=t,x-=t;
            }
            y = (min(l,r)+(x-1)/2)*2+1;
        }

        fr(k,j,i) res[a[k][1]]=y; 
    }
    tr(e,res) cout<<e<<" ";
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