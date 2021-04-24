/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:(a))
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
#define int ll
int MAX=1e5;
vector<vector<iii>> g;
vi p,res;
vii a;
vector<vii> q;

template<class T>
class SegTree{
    vector<T> seg;
    int n;
    T (*combine)(T,T);
    T build(const vector<T>&,int,int,int=0);
    T update(int,int,int,T,int=0);
    T get(int,int,int,int,int=0);
    public:
    SegTree(vector<T> a,T (*combine)(T,T)){
        n=a.size(),this->combine=combine;
        seg.assign(pow(2,ceil(log2(n))+1)-1,0);
        build(a,0,n-1);
    }
    T get(int l,int r){ return get(0,n-1,l,r); }
    T update(int i,T val){ return update(0,n-1,i,val); }
    void print(){
        tr(e,seg) cout<<e<<" ";
        cout<<"\n";
    }
};
template <class T>
T SegTree<T>::build(const vector<T> &a,int l,int r,int i){
    if(l==r) return seg[i]=a[l];
    int m=l+(r-l)/2;
    return seg[i]=combine(build(a,l,m,i*2+1),build(a,m+1,r,i*2+2));
}
template <class T>
T SegTree<T>::get(int l,int r,int ql, int qr, int i){
    if(qr<l||ql>r) return 0;
    if(qr>=r&&ql<=l) return seg[i];
    int m=l+(r-l)/2;
    return combine(get(l,m,ql,qr,i*2+1),get(m+1,r,ql,qr,i*2+2));
}
template <class T>
T SegTree<T>::update(int l,int r,int q,T val,int i){
    if(l==r) return seg[i]=val;
    int m=l+(r-l)/2;
    if(q<=m) return seg[i]=combine(update(l,m,q,val,i*2+1),seg[i*2+2]);
    else return seg[i]=combine(seg[i*2+1],update(m+1,r,q,val,i*2+2));
}

SegTree<int> seg(vi(2e5+1,0),[](int x,int y){
    return __gcd(x,y);
});

void dfs(int v,ii x,int par=-1){
    p[v]=par,a[v]=x;
    tr(e,g[v]){
        if(e.F!=par){
            dfs(e.F,e.S,v);
        }
    }
}

void dfs2(int v){
    int l=a[v].F,am=a[v].S;
    seg.update(l,am);
    tr(e,q[v]){
        res[e.S]=seg.get(0,e.F);
    }
    tr(e,g[v]){
        if(e.F!=p[v]) dfs2(e.F);
    }
    seg.update(l,0);
}

void solve(){
    int n,m;
    cin>>n>>m;
    g=vector<vector<iii>>(n);
    p=vi(n);
    res=vi(m);
    q=vector<vii>(n);
    a=vii(n);
    fr(i,0,n-1){
        int x,y,z,w;
        cin>>x>>y>>z>>w,x--,y--;
        g[x].pb({y,{z,w}});
        g[y].pb({x,{z,w}});
    }
    fr(i,0,m){
        int v,w;
        cin>>v>>w,v--;
        q[v].pb({w,i});
    }
    dfs(0,{0,0});
    dfs2(0);
    tr(e,res) cout<<e<<" ";
    cout<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=0;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}