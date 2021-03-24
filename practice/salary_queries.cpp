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
vi a,b(1e7,0),seg(pow(2,ceil(log2(1e7))+1)-1,0);
map<int,int> sal;
 
inline int buck(int &a){
    return (a-1)/100;
}
 
int build(int l,int r,int i){
    if(l==r) return seg[i]=b[l];
    int m=l+(r-l)/2;
    return seg[i]=build(l,m,i*2+1)+build(m+1,r,i*2+2);
}
 
int update(int l,int r,int q,int val,int i){
    if(l==r) return seg[i]+=val;
    int m=l+(r-l)/2;
    if(q<=m) return seg[i]=seg[i*2+2]+update(l,m,q,val,i*2+1);
    else return seg[i]=seg[i*2+1]+update(m+1,r,q,val,i*2+2);
}
 
int get(int l,int r,int ql, int qr, int i){
    if(qr<l||ql>r) return 0;
    if(qr>=r&&ql<=l) return seg[i];
    int m=l+(r-l)/2;
    return get(l,m,ql,qr,i*2+1)+get(m+1,r,ql,qr,i*2+2);
}
 
int calc(int l,int h){
    auto it=sal.lower_bound(l);
    int res=0;
    while(it!=sal.end()&&it->first<=h){
        res+=it->second;
        it++;
    }
    return res;
}
 
void solve(){
    int n,q;
    cin>>n>>q;
    a.resize(n);
    tr(e,a) {
        cin>>e;
        b[buck(e)]++;
        sal[e]++;
    }
    build(0,b.size()-1,0);
    while(q--){
        char ch;
        int x,y;
        cin>>ch>>x>>y;
        if(ch=='!'){
            x--;
            update(0,b.size()-1,buck(a[x]),-1,0);
            update(0,b.size()-1,buck(y),1,0);
            sal[a[x]]--,sal[y]++;
            a[x]=y;
        }
        else{
            int l=buck(x),r=buck(y),res=0;
            if(r!=l) res+=get(0,b.size()-1,l+1,r-1,0)+calc(max(x,r*100+1),y);
            res+=calc(x,min(y,(l+1)*100));
            cout<<res<<"\n";
        }
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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