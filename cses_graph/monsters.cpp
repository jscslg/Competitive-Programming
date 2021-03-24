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
int n,m,xt[]={1,0,-1,0},yt[]={0,1,0,-1};
int MAX=1e5+1;
ii s;
char a[1001][1001],at[]={'D','R','U','L'};

void dfs(ii p,vector<char> &v,vvi &f){
    f[p.F][p.S]=1;
    fr(i,0,4){
        int c=p.F+xt[i],d=p.S+yt[i];
        if(a[c][d]=='A'&&!f[c][d]){
            v.pb(at[i]);
            if(c==n-1||d==m-1||c==0||d==0){
                cout<<v.size()<<"\n";
                tr(e,v) cout<<e;
                exit(0);
            }
            dfs({c,d},v,f);
            v.pop_back();
        }
    }
}

void solve(){
    cin>>n>>m;
    queue<ii> q;
    fr(i,0,n) fr(j,0,m) {
        cin>>a[i][j];
        if(a[i][j]=='M') q.push({i,j});
    }
    fr(i,0,n) fr(j,0,m) {
        if(a[i][j]=='A') q.push({i,j}),s={i,j};
    }
    if(s.F==n-1||s.F==0||s.S==m-1||s.S==0) {
        cout<<"YES\n0";
        return;
    }
    while(!q.empty()){
        int x=q.front().F,y=q.front().S;
        q.pop();
        fr(i,0,4){
            int c=xt[i]+x,d=yt[i]+y;
            if(c<0||d<0||d>=m||c>=n) continue;
            if(a[x][y]=='M'){
                if(a[c][d]=='.') q.push({c,d}),a[c][d]='M';
            }
            else{
                if(a[c][d]=='.') {
                    q.push({c,d}),a[c][d]='A';
                    if(c==n-1||d==m-1||c==0||d==0) {
                        cout<<"YES\n";
                        // fr(i,0,n) {
                        //     fr(j,0,m) cout<<a[i][j]<<" ";
                        //     cout<<"\n";
                        // }
                        vector<char> path;
                        vvi f(n,vi(m,0));
                        dfs(s,path,f);
                        return;
                    }
                }
            }
        }
    }
    cout<<"NO\n";

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