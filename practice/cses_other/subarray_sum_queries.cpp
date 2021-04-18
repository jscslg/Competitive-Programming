/*
~~~JsCode~~~
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define tr(i,a) for(auto& i:a)
#define int ll
#define fr(i,a,b) for(int i=(a);i<(b);++i)
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1;

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

struct node{
    int tot,pre,suf,sub;
    node (){}
    node(int a){
        tot=pre=suf=sub=a;
    }
};

node combine(node x,node y){
    node a;
    a.pre=max(x.pre,x.tot+y.pre);
    a.suf=max(y.suf,y.tot+x.suf);
    a.sub=max({y.sub,x.sub,x.suf+y.pre});
    a.tot=x.tot+y.tot;
    return a;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<node> a(n);
    tr(e,a) {
        int i;cin>>i;
        e=node(i);
    }
    SegTree<node> s(a,combine);
    while(m--){
        int k,x;
        cin>>k>>x,k--;
        s.update(0,n-1,k,a[k]=x);
        cout<<max(0ll,s.get(0,n-1,0,n-1).sub)<<"\n";
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