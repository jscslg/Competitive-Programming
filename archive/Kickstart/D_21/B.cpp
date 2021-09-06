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
    int n,c,x=0,s=0;
    cin>>n>>c;
    ve<ar(2)> a(2*n);
    ve<ar(2)> res;
    fr(i,0,n){
        cin>>a[2*i][0],a[2*i][1]=1;
        cin>>a[2*i+1][0],a[2*i+1][1]=0;
    }
    sort(all(a));
    int i=0;
    while(i<2*n){
        int y=a[i][0],z=x;
        while(i<2*n && a[i][0]==y) {
            if(a[i][1]) x++;
            else x--;
            if(a[i][1]==0) z=x;
            i++;
        }
        if(i==2*n) break;
        if(a[i][0]-a[i-1][0]-1>0) res.pb({x,a[i][0]-a[i-1][0]-1});
        if(z) res.pb({z,1});
    }
    sort(all(res),greater<ar(2)>());
    tr(e,res){
        //cout<<e[0]<<" "<<e[1]<<"\n";
        if(c>=e[1]){
            c-=e[1];
            s+=e[0]*e[1];
        }
        else{
            s+=c*e[0];
            c=0;
        }
    }
    cout<<n+s<<"\n";
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
        cout<<"Case #"<<i<<": ";
        solve();
    }
    #ifdef LOCAL_JUDGE
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        cerr << "Time taken : " << duration.count() / 1000000.0 << "seconds"<< "\n";
    #endif
    return 0;
}