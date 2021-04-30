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
#define frv(i,a,b) for(int i=(a);i>=(b);--i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<int>
#define hmin priority_queue<int,vi,greater<int>>
#define MOD 1000000007
//#define int ll
int MAX=1e5,xx[]={1,0,-1,0},yy[]={0,1,0,-1};
vvi vis;
vector<string> a;
int n,m;

inline bool v(int i,int j){
    return i>=0&&j>=0&&i<n&&j<m&&!vis[i][j]&&a[i][j]!='#';
}

void solve(){
    string res;
    cin>>n>>m;
    a = vector<string>(n);
    vis= vvi(n,vi(m,0));
    vector<vii> prv(n,vii(m));
    tr(e,a) cin>>e;
    queue<ii> q;
    fr(i,0,n) fr(j,0,m) if(a[i][j]=='A') q.push({i,j}),vis[i][j]=1;
    while(!q.empty()){
        int i=q.front().F,j=q.front().S;
        q.pop();
        fr(k,0,4){
            int x=i+xx[k],y=j+yy[k];
            if(v(x,y)){
                vis[x][y]=vis[i][j]+1;
                prv[x][y]={i,j};
                if(a[x][y]=='B'){
                    cout<<"YES\n"<<vis[x][y]-1<<"\n";
                    int p=x,q=y;
                    while(a[p][q]!='A'){
                        int pp=prv[p][q].F,qq=prv[p][q].S;
                        if(pp-p==1) res.pb('U');
                        else if(pp-p==-1) res.pb('D');
                        else if(qq-q==1) res.pb('L');
                        else res.pb('R');
                        p=pp,q=qq;
                    }
                    reverse(all(res));
                    cout<<res;
                    return;
                }
                q.push({x,y});
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