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
    vector<T> seg;
    vector<pair<T,int>> lazy;
    int n,size;
    T (*combine)(T,T);
    T build(const vector<T>&,int,int,int=0);
    T setUpdate(int,int,int,int,T,int=0);
    T incUpdate(int,int,int,int,T,int=0);
    T get(int,int,int,int,int=0);
    void upd(int i,int l,int r){
        int t=lazy[i].S;
        if(t==0) return;
        if(t==1) seg[i]+=(r-l+1)*lazy[i].F;
        else seg[i]=(r-l+1)*lazy[i].F;
        if(l!=r){
            fr(k,1,3){
                int j=i*2+k;
                if(t==1){
                    lazy[j].F+=lazy[i].F;
                    if(lazy[j].S==0) lazy[j].S=1;
                }
                else lazy[j]=lazy[i];
            }
        }
        lazy[i]={0,0};
    }
    public:
    SegTree(vector<T> a,T (*combine)(T,T)){
        n=a.size(),size=pow(2,ceil(log2(n))+1)-1,this->combine=combine;
        lazy.assign(size,{0,0}),seg.assign(size,0);
        build(a,0,n-1);
    }
    T get(int l,int r){ return get(0,n-1,l,r); }
    T incUpdate(int l,int r,T val){ return incUpdate(0,n-1,l,r,val); }
    T setUpdate(int l,int r,T val){ return setUpdate(0,n-1,l,r,val); }
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
    upd(i,l,r);
    if(qr<l||ql>r) return 0;
    if(qr>=r&&ql<=l) return seg[i];
    int m=l+(r-l)/2;
    return combine(get(l,m,ql,qr,i*2+1),get(m+1,r,ql,qr,i*2+2));
}
template <class T>
T SegTree<T>::setUpdate(int l,int r,int ql,int qr,T val,int i){
    upd(i,l,r);
    if(l>qr || r<ql) return seg[i];
    if(l>=ql && r<=qr) {
        if(l!=r) {
            lazy[i*2+1]={val,2};
            lazy[i*2+2]={val,2};
        }
        return seg[i]=(r-l+1)*val;
    }
    int m=l+(r-l)/2;
    return seg[i]=combine(setUpdate(l,m,ql,qr,val,i*2+1),setUpdate(m+1,r,ql,qr,val,i*2+2));
}
template <class T>
T SegTree<T>::incUpdate(int l,int r,int ql,int qr,T val,int i){
    upd(i,l,r);
    if(l>qr || r<ql) return seg[i];
    if(l>=ql && r<=qr) {
        if(l!=r) {
            fr(k,1,3){
                int j=i*2+k;
                lazy[j].F+=val;
                if(lazy[j].S==0) lazy[j].S=1;
            }
        }
        return seg[i]+=(r-l+1)*val;
    }
    int m=l+(r-l)/2;
    return seg[i]=combine(incUpdate(l,m,ql,qr,val,i*2+1),incUpdate(m+1,r,ql,qr,val,i*2+2));
}

void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n);
    tr(e,a) cin>>e;
    SegTree<int> seg(a,[](int x,int y){
        return x+y;
    });
    while(q--){
        int t,x,y,z;
        cin>>t>>x>>y,x--,y--;
        if(t==1){
            cin>>z;
            seg.incUpdate(x,y,z);
        }
        else if(t==2){
            cin>>z;
            seg.setUpdate(x,y,z);
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
    //cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}