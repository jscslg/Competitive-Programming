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
int MAX=1e5,cnt=0;
vvi g;
vi a,s;
map<int,int> m;

template<class T>
class SegTree{
    vector<T> seg;
    int n;
    T build(const vector<T>&,int,int,int=0);
    T (*combine)(T,T);
    public:
    SegTree(vector<T> a,T (*combine)(T,T)){
        n=a.size();
        this->combine=combine;
        seg.assign(pow(2,ceil(log2(n))+1)-1,0);
        build(a,0,n-1);
    }
    void print(){
        tr(e,seg) cout<<e<<" ";
        cout<<endl;
    }
    T update(int,int,int,T,int=0);
    T get(int,int,int,int,int=0);
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

int dfs(int v,int par=-1){
    m[v]=cnt++;
    tr(e,g[v]){
        if(e==par) continue;
        s[v]+=dfs(e,v);
    }
    return s[v]+1;
}

void solve(){
    int n,q;
    cin>>n>>q;
    a=vi(n);
    s=vi(n,0);
    g=vvi(n);
    tr(e,a) cin>>e;
    fr(i,0,n-1){
        int a,b;
        cin>>a>>b,a--,b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(0);
    //tr(e,s) cout<<e<<" ";
    vi b(n);
    fr(i,0,n){
        b[m[i]]=a[i];
    }
    SegTree<int> seg(b,[](int x,int y)->int{
        return x+y;
    });
    while(q--){
        int z,sub;
        cin>>z>>sub,sub--;
        if(z==2){
            int x=m[sub];
            cout<<seg.get(0,n-1,x,x+s[sub])<<"\n";
        }
        else{
            int x;
            cin>>x;
            seg.update(0,n-1,m[sub],x);
        }
    }
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