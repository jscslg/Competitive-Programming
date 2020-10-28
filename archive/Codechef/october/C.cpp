#include <bits/stdc++.h>
#define ll long long
#define ldb long double
#define MOD 1000000007
#define any_data int
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<any_data>
#define vvi vector<vi>
#define ii pair<any_data,any_data>
#define iii pair<any_data,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
void c_p_c(){ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout); }
const int mx=2e5+1;
vii p;

int find(int v){
    if(p[v].F==v) return v;
    p[v].F= find(p[v].F);
    return p[v].F;
}

void join(int x,int y){
    x=find(x);
    y=find(y);
    if(p[x].S>p[y].S) p[y].F=p[x].F;
    else if(p[x].S<p[y].S) p[x].F=p[y].F;
    else{
        p[x].F=p[y].F;
        p[y].S++;
    }
}

void solve(){
    int n,d,l=0;
    cin>>n>>d;
    vvi a(n,vi(d));
    vector<iii> w((n*(n-1))/2,{0,{0,0}});
    f(i,0,n) f(j,0,d) cin>>a[i][j];
    f(i,0,n){
        f(j,i+1,n){
            f(k,0,d) w[l].F+=abs(a[i][k]-a[j][k]);
            w[l].S.F=i,w[l].S.S=j;
            ++l;
        }
    }
    sort(all(w),greater<iii>());
    ll res=0;
    p.resize(n);
    f(i,0,n) p[i]={i,0};
    f(i,0,l){
        if(find(w[i].S.F)!=find(w[i].S.S)){
            res+=w[i].F;
            join(w[i].S.F,w[i].S.S);
        }
    }
    cout<<res;
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    c_p_c();
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}