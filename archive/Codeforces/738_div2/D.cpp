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
ve<vi> g1,g2;
ve<ar(2)> c1,c2;
vi v1,v2;

void rec1(int i,int c){
    c1[i]={c,0};
    c1[c][1]++;
    v1[i]=1;
    tr(e,g1[i]){
        if(!v1[e]) rec1(e,c);
    }
}
void rec2(int i,int c){
    c2[i]={c,0};
    c2[c][1]++;
    v2[i]=1;
    tr(e,g2[i]){
        if(!v2[e]) rec2(e,c);
    }
}

int get1(int x){
    if(c1[x][0]!=x) c1[x][0]= get1(c1[x][0]);
    return c1[x][0];
}
int get2(int x){
    if(c2[x][0]!=x) c2[x][0]= get2(c2[x][0]);
    return c2[x][0];
}
void un1(int x,int y){
    x=get1(x),y=get1(y);
    if (c1[x][1] < c1[y][1])
        c1[x][0] = y;
    else if (c1[x][1] > c1[y][1])
        c1[y][0] = x;
    else {
        c1[y][0] = x;
        c1[x][1]++;
    }
}
void un2(int x,int y){
    x=get2(x),y=get2(y);
    if (c2[x][1] < c2[y][1])
        c2[x][0] = y;
    else if (c2[x][1] > c2[y][1])
        c2[y][0] = x;
    else {
        c2[y][0] = x;
        c2[x][1]++;
    }
}

void solve(){
    int n,m1,m2,s=0;
    cin>>n>>m1>>m2;
    g1 =ve<vi>(n);
    g2 = ve<vi> (n);
    ve<ar(2)> res;
    fr(i,0,m1) {
        int x,y;
        cin>>x>>y,x--,y--;
        g1[x].pb(y);
        g1[y].pb(x);
    }
    fr(i,0,m2) {
        int x,y;
        cin>>x>>y,x--,y--;
        g2[x].pb(y);
        g2[y].pb(x);
    }
    c1=ve<ar(2)>(n,{-1,0}),c2=ve<ar(2)>(n,{-1,0});
    v1=vi(n,0),v2=vi(n,0);
    fr(i,0,n) c1[i]={i,0},c2[i]={i,0};
    fr(i,0,n){
        if(!v1[i]) rec1(i,i);
    }
    fr(i,0,n){
        if(!v2[i]) rec2(i,i);
    }
    fr(i,0,n){
        fr(j,i+1,n){
            int x1=get1(i),y1=get1(j);
            int x2=get2(i),y2=get2(j);
            if(x1!=y1 && x2!=y2) {
                un1(x1,y1);
                un2(x2,y2);
                s++;
                res.pb({i+1,j+1});
            }
        }
    }
    cout<<s<<"\n";
    tr(e,res) cout<<e[0]<<" "<<e[1]<<"\n";
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