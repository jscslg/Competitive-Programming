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
int n,m;
vector<vii> g;

bool findUtil(int v,int b,vi &f){
    if(v==b) return 1;
    f[v]=1;
    bool res=0;
    tr(i,g[v]){
        int e=i.F,c=i.S;
        if(f[e]) continue;
        res|=findUtil(e,b,f);
        if(res) return 1;
    }
    return res;
}

bool find(int a,int b){
    vi f(n,0);
    return findUtil(a,b,f);
}

bool checkCycleUtil(int v,int sum,int s,vi &f){
    if(v==s) return sum>0;
    f[v]=1;
    bool res=0;
    tr(i,g[v]){
        int e=i.F,c=i.S;
        if(f[e]) continue;
        res|=checkCycleUtil(e,sum+c,s,f);
    }
    return res;
}

bool check(int v){
    vi f(n,0);
    bool res=0;
    tr(i,g[v]){
        int e=i.F,c=i.S;
        res|=checkCycleUtil(e,c,v,f);
    }
    return res;
}

void solve(){
    cin>>n>>m;
    g.assign(n,vii());
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        bool flag=0;
        tr(j,g[a]){
            if(j.F==b) j.S=max(j.S,c),flag=1;
        }
        if(!flag) g[a].pb({b,c}); 
    }
    fr(i,0,n-1){
        if(find(i,n-1) && find(0,i) && check(i)) {
            cout<<"-1\n";
            return;
        }
    }
    vi d(n,LLONG_MIN);
    d[0]=0;
    fr(i,0,n-1){
        fr(i,0,n){
            tr(j,g[i]){
                int e=j.F,c=j.S;
                d[e]= max(d[e],d[i]+c);
            }
        }
    }
    cout<<d[n-1]<<"\n";
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