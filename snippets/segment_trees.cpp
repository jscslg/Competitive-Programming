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