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

template<class T>
class SegTree{
    vector<T> seg,lazy;
    int n,size;
    T (*combine)(T,T);
    T get(int,int,int,int,int=0);
    T update(int,int,int,T,int=0);
    T rangeUpdate(int,int,int,int,T,int=0);
    void upd(int,int,int);
    public:
    SegTree(vector<T> a,T (*combine)(T,T)){
        n=a.size(),size=pow(2,ceil(log2(n))+1)-1,this->combine=combine;
        lazy.assign(size,0),seg.assign(size,0);
        for(int i=0;i<n;i++) update(i,a[i]);
    }
    void print(){ tr(e,seg) cout<<e<<" ";cout<<"\n"; }
    T get(int l,int r){ return get(0,n-1,l,r); }
    T update(int i,T val) { return update(0,n-1,i,val); }
    T rangeUpdate(int l,int r,T val){ return rangeUpdate(0,n-1,l,r,val); }
};
template<class T>
void SegTree<T>::upd(int i,int l,int r){
    if(lazy[i]!=0) {
        seg[i]+=(r-l+1)*lazy[i];
        if(l!=r) lazy[i*2+1]+=lazy[i],lazy[i*2+2]+=lazy[i];
        lazy[i]=0;
    }
}
template<class T>
T SegTree<T>::get(int l,int r,int ql, int qr, int i){
    upd(i,l,r);
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
template<class T>
T SegTree<T>::rangeUpdate(int l,int r,int ql,int qr,T val,int i){
    upd(i,l,r);
    if(l>qr || r<ql) return seg[i];
    if(l>=ql && r<=qr) {
        if(l!=r) lazy[i*2+1]+=val,lazy[i*2+2]+=val;
        return seg[i]+=(r-l+1)*val;
    }
    int m=l+(r-l)/2;
    return seg[i]=combine(rangeUpdate(l,m,ql,qr,val,i*2+1),rangeUpdate(m+1,r,ql,qr,val,i*2+2));
}

void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n,0);
    SegTree<int> seg(a,[](int x,int y){
        return x+y;
    });
    while(q--){
        int t,x,y,z;
        cin>>t>>x>>y,x--,y--;
        if(t==0){
            cin>>z;
            seg.rangeUpdate(x,y,z);
        }
        else{
            cout<<seg.get(x,y)<<"\n";
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
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}