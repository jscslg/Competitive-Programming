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
//#define int ll
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
        seg.assign(pow(2,ceil(log2(n))+1)-1,T());
        build(a,0,n-1);
    }
    void print(){
        tr(e,seg){
            cout<<e.m<<" ";
            //tr(f,e.pre) cout<<f<<" ";
            //cout<<"\n";
        }
        cout<<"\n";
    }
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
    if(qr<l||ql>r) return T();
    if(qr>=r&&ql<=l) return seg[i];
    int m=l+(r-l)/2;
    return combine(get(l,m,ql,qr,i*2+1),get(m+1,r,ql,qr,i*2+2));
}
    
struct node{
    vi pre,post,sub;
    int m;
    node(){m=0;}
    node(int a){
        pre.assign(1,a);
        post.assign(1,a);
        sub.assign(1,a);
        m=1;
    }
    node(vi a,vi b,vi c,int m){
        pre=a,post=b,sub=c,this->m=m;
    }
};

node combine(node a,node b){
    if(a.m==0) return b;
    if(b.m==0) return a;
    vi pre,post,sub;
    pre=a.pre;
    for(auto it=upper_bound(all(b.pre),pre.back());it!=b.pre.end();it++){
        pre.pb(*it);
    }
    if(b.pre.back()==b.post.back()&&b.post.back()>a.post.back()) {
        post=a.post;
        for(auto it=upper_bound(all(b.post),post.back());it!=b.post.end();it++){
            post.pb(*it);
        }
    }
    if(post.size()<=b.post.size()) post=b.post;
    int u1=b.pre.end()-upper_bound(all(b.pre),a.sub.back()),u2=b.pre.end()-upper_bound(all(b.pre),a.post.back());
    int s1=a.sub.size()+u1,s2=a.post.size()+u2,s3=b.sub.size();
    int b1=(u1==0)?a.sub.back():b.pre.back(),b2=(u2==0)?a.sub.back():b.pre.back(),b3=b.sub.back();
    ii c;
    if(s1>s2){
        if(s1>s3) c={s1,b1};
        else if(s1==s3) c={s1,min(b1,b3)};
        else c={s3,b3};
    }
    else if(s1==s2){
        if(s2==s3) c={s1,min({b1,b2,b3})};
        else if(s3>s2) c={s3,b3};
        else c={s1,min(b1,b2)};
    }
    else{
        if(s2>s3) c={s2,b2};
        else if(s2==s3) c={s2,min(b2,b3)};
        else c={s3,b3};
    }
    if(c.F==s1&&c.S==b1){
        sub=a.sub;
        for(auto it=upper_bound(all(b.pre),sub.back());it!=b.pre.end();it++){
            sub.pb(*it);
        }
    }
    else if(c.F==s2&&c.S==b2){
        sub=a.post;
        for(auto it=upper_bound(all(b.pre),sub.back());it!=b.pre.end();it++){
            sub.pb(*it);
        }
    }
    else sub=b.sub;
    /*cout<<"Pre: ";
    tr(e,pre) cout<<e<<" ";
    cout<<"Post: ";
    tr(e,post) cout<<e<<" ";
    cout<<"M: "<<size<<"\n";*/
    return node(pre,post,sub,sub.size());
}

void solve(){
    int n,q,z,ans=0;
    cin>>n>>q>>z;
    vector<node> a(n);
    tr(e,a) {
        int i;
        cin>>i,e=i;
    }
    SegTree<node> s(a,combine);
    //s.print();
    while(q--){
        int x,y,L,R;
        cin>>x>>y;
        L=(x+z*ans-1)%n;
        R=(y+z*ans-1)%n;
        if(L>R) swap(L,R);
        ans=s.get(0,n-1,L,R).m;
        cout<<ans<<"\n";
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
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