#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb long double
//#define int ll
#define MOD 1000000007
#define fr(i,a) for(int i=0;i<(a);++i)
#define tr(i,a) for(auto& i:a)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define INIT 0
const int MAX=1e6;
void initialize(){}

void solve(){
    int n,h=0;
    cin>>n;
    vvi g(n,vi());
    fr(i,n-1){
        int a,b;cin>>a>>b;--a,--b;
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<int> q;
    q.push(0);
    q.push(-1);
    vector<bool> f(n,0);
    vi res(n,0);
    while(!q.empty()){
        while(q.front()!=-1){
            int e=q.front();
            q.pop();
            f[e]=1;
            tr(i,g[e]) if(!f[i]) q.push(i);
            if(h%2==0) res[e]=3;
            else res[e]=2;
        }
        q.pop();
        if(!q.empty()) q.push(-1);
        ++h;
    }
    tr(i,res) cout<<i<<" ";
    cout<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
    #endif
    #if INIT
    initialize();
    #endif
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}