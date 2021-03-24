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
#define hmax priority_queue<ii>
#define hmin priority_queue<int,vi,greater<int>>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define MOD 1000000007
int MAX=1e5+1;

void solve(){
    int n;
    cin>>n;
    vi w(n);
    tr(e,w) cin>>e;
    vvi g(n,vi());
    fr(i,0,n-1){
        int a,b;cin>>a>>b;
        a--,b--;
        g[a].pb(b),g[b].pb(a);
    }
    hmax h;
    int sum=0;
    fr(i,0,n){
        if(g[i].size()>1) h.push({w[i],g[i].size()-1});
        sum+=w[i];
    }
    cout<<sum<<" ";
    while(!h.empty()){
        ii e=h.top();
        h.pop();
        while(e.S--){
            sum+=e.F;
            cout<<sum<<" ";
        }
    }
    cout<<"\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    //INIT
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}