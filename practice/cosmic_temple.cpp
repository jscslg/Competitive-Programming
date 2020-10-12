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
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define uniquefy(v) v.resize(unique(v.begin(), v.end()) - v.begin())
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INIT 0
using namespace std;
void c_p_c(){ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout); }
const int mx=1e6;
void initialize(){}
int n;
vvi g;
vi down,num,res;

void dfsdown(int i=0,int p=-1){
    down[i]=0;
    num[i]=0;
    for(auto& e:g[i]){
        if(e==p) continue;
        dfsdown(e,i);
        down[i]+=down[e]+num[e];
        num[i]+=num[e];
    }
    num[i]+=1;
}

void dfsres(int v,int p){
    res[v]=res[p]+n-2*num[v];
    for(auto& e:g[v]){
        if(e==p) continue;
        dfsres(e,v);
    }
}

void solve(){
    cin>>n;
    g.resize(n);
    f(i,0,n-1){
        int a,b;
        cin>>a>>b;
        g[a].pb(b);
        g[b].pb(a);
    }
    down.resize(n);
    num.resize(n);
    res.resize(n);

    dfsdown();

    res[0]=down[0];
    for(auto& e:g[0]){
        dfsres(e,0);
    }
    f(i,0,n) cout<<res[i]<<" ";
}

int main(){
    fast;
    #ifndef ONLINE_JUDGE
    c_p_c();
    #endif
    #if INIT
    initialize();
    #endif
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}