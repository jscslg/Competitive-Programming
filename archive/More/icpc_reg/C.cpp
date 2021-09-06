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
const int MAX=1e6+1;
vi pr;
ve<ar(2)> p;

int get(int i){
    if (p[i][0] != i)
        p[i][0]
            = get(p[i][0]);
 
    return p[i][0];
}

void Union(int x,int y){
    x=get(x);
    y=get(y);
    if (p[x][1] < p[y][1])
        p[x][0] = y;
    else if (p[x][1] > p[y][1])
        p[y][0] = x;
    else {
        p[y][0] = x;
        p[x][1]++;
    }
}

void solve(){
    int n,mn=INT_MAX,c=1;
    cin>>n;
    vi a(n);
    tr(e,a) cin>>e;
    if(n==1){
        cout<<"0\n";
        return;
    }
    map<int,int> m;
    p = ve<ar(2)>(n);
    fr(i,0,n) p[i]={i,0};
    fr(i,0,n){
        int x=a[i],cur=p[i][0];
        while(pr[x]>1){
            mn=min(mn,pr[x]);
            
            if(m.find(pr[x])!=m.end()) Union(m[pr[x]],cur);
            else m[pr[x]]=cur;
            
            x/=pr[x];
        }
        // tr(e,m) cout<<e.first<<"x"<<e.second<<" ";
        // cout<<"\n";
    }
    set<int> s;
    fr(i,0,n){
        //cout<<p[i][0]<<" ";
        s.insert(get(i));
    }
    c=s.size();
    // cout<<"\n"<<c<<" ";
    cout<<min(mn*(c-1),2*c)<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
        auto start = chrono::high_resolution_clock::now();
        freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    pr = vector<int>(MAX+1,1);
    for(int i=2;i*i<=MAX;i++){
        if(pr[i]==1){
            for(int j=i*i;j<=MAX;j+=i) if(pr[j]==1) pr[j]=i;
        }
    }
    fr(i,0,MAX+1) if(pr[i]==1) pr[i]=i;
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