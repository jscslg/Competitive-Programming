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
vi a,seg;

int get(int l,int r,int val,int i){
    if(l==r) {
        seg[i]=0;
        return l;
    }
    int m=l+(r-l)/2;
    seg[i]--;
    if(seg[i*2+1]>=val) return get(l,m,val,i*2+1);
    else return get(m+1,r,val-seg[i*2+1],i*2+2);
}

int build(int l,int r,int i){
    if(l==r) return seg[i]=1;
    int m=l+(r-l)/2;
    return seg[i]=build(l,m,i*2+1)+build(m+1,r,i*2+2);
}

void solve(){
    int n;
    cin>>n;
    a.resize(n);
    tr(e,a) cin>>e;
    int p=ceil(log2(n))+1;
    seg.resize((1ll<<p)-1,0);
    build(0,n-1,0);
    //tr(e,seg) cout<<e<<" ";
    //cout<<endl;
    fr(i,0,n){
        int x;
        cin>>x;
        cout<<a[get(0,n-1,x,0)]<<" ";
        //tr(e,seg) cout<<e<<" ";
        //cout<<endl;
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