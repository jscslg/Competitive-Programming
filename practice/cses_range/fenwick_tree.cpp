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
class Bit{
    int size;
    vector<T> tree;
    public:
    Bit(vector<T> a){
        size=a.size()+1;
        tree.assign(size,0);
        for(int i=0;i<size-1;i++) update(i,a[i]); 
    }
    T get(int);
    void update(int,T);
};
template<class T>
void Bit<T>::update(int i,T val){
    i++;
    while(i<size) tree[i]+=val,i+=(i&(-i));
}
template<class T>
T Bit<T>::get(int i){
    T res=0;i++;
    while(i>0) res+=tree[i],i-=(i&(-i));
    return res; 
}

void solve(){
    int n,q;
    cin>>n>>q;
    vi a(n);
    tr(e,a) cin>>e;
    Bit<int> b(a);
    while(q--){
        int t,x,y;
        cin>>t>>x>>y,x--;
        if(t==1) b.update(x,y-a[x]),a[x]=y;
        else cout<<b.get(y-1)-(x?b.get(x-1):0)<<"\n";
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