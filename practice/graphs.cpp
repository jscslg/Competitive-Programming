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
//#define int ll
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
vi p;
vvi g;

void solve(){
    int n,m,d=0;
    cin>>n>>m;
    p.assign(n,0);
    g.assign(n,vi());
    vi res;
    fr(i,0,m){
        int a,b;
        cin>>a>>b,--a,--b,g[a].pb(b),g[b].pb(a);
    }
    fr(j,0,n){
        if(p[j]) continue;
        queue<int> q;
        q.push(j);
        q.push(-1);
        while(!q.empty()){
            while(q.front()!=-1){
                int e=q.front();
                q.pop();
                p[e]=d%2?2:1;
                tr(i,g[e]){
                    if(!p[i]) q.push(i);
                    if(p[i]==(d%2?2:1)){
                        cout<<"IMPOSSIBLE\n";
                        return;
                    }
                }
            }
            q.pop();
            if(!q.empty()) q.push(-1),++d;
        }
    }
    tr(i,p) cout<<i<<" ";
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