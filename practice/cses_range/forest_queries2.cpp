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
//#define int ll
int MAX=1e5;

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
    T update(int i,T val=1){ return update(0,n-1,i,val); }
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
    if(l==r) return seg[i]+=val;
    int m=l+(r-l)/2;
    if(q<=m) return seg[i]=combine(update(l,m,q,val,i*2+1),seg[i*2+2]);
    else return seg[i]=combine(seg[i*2+1],update(m+1,r,q,val,i*2+2));
}
int comb(int a,int b){
    return a+b;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vvi a(n,vi(n)),b;
    tr(e,a) tr(i,e){
        char c;
        cin>>c;
        i=c=='*';
    }
    b=a;
    fr(i,0,n){
        fr(j,1,n) b[i][j]+=b[i][j-1];
    }
    fr(j,1,n){
        fr(i,0,n) b[j][i]+=b[j-1][i];
    }
    SegTree<int> r1(vi(n,0),comb),c1(vi(n,0),comb),r2(vi(n,0),comb),c2(vi(n,0),comb);
    while(q--){
        int t,x1,y1,x2,y2;
        cin>>t>>x1>>y1,x1--,y1--;
        if(t==1){
            if(a[x1][y1]==1) r2.update(x1),c2.update(y1);
            else r1.update(x1),c1.update(y1);
            a[x1][y1]=!a[x1][y1];
        }
        else{
            cin>>x2>>y2,x2--,y2--;
            int s=b[x2][y2],x=min(r1.get(0,x2),c1.get(0,y2)),y=min(r2.get(0,x2),c2.get(0,y2));
            if(y1) s-=b[x2][y1-1],x-=min(r1.get(0,x2),c1.get(0,y1-1)),y-=min(r2.get(0,x2),c2.get(0,y1-1));
            if(x1) s-=b[x1-1][y2],x-=min(r1.get(0,x1-1),c1.get(0,y2)),y-=min(r2.get(0,x1-1),c2.get(0,y2));
            if(x1 && y1) s+=b[x1-1][y1-1],x+=min(r1.get(0,x1-1),c1.get(0,y1-1)),y+=min(r2.get(0,x1-1),c2.get(0,y1-1));;
            cout<<s+x-y<<"\n";
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