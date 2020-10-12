#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
#define int ll
#define MOD 1000000007
#define f(i,a,b) for(int i=(a);i<(b);++i)
#define f_(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define INIT 0
const int mx=1e6;
void initialize(){}
int x2,y2,res;
ii up(ii p){
    if(p.S+2*p.F>0) return {p.F,p.S+2*p.F};
    else return {-p.F,-(p.S+2*p.F)};
}
ii down(ii p){
    if(p.S-2*p.F>0) return {p.F,p.S-2*p.F};
    else return {-p.F,-(p.S-2*p.F)};
}
ii right(ii p){
    return {p.F+2*p.S,p.S};
}
ii left(ii p){
    return {p.F-2*p.S,p.S};
}
void rec(ii p,int c=0){
    if(p.F==x2&&p.S==y2) {
        res=min(res,c);
        return;
    }
    if(c==6) return;
    rec(up(p),c+1);
    rec(down(p),c+1);
    rec(right(p),c+1);
    rec(left(p),c+1);
}
void solve(){
    ii ini;
    cin>>ini.F>>ini.S>>x2>>y2;
    res=10;
    rec(ini);
    cout<<res<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}