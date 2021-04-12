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
#define int ll
#define tr(i,a) for(auto& i:a)
#define fr(i,n) for(int i=0;i<(n);++i)
#define fr1(i,n) for(int i=1;i<=(n);++i)
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>
#define hmax priority_queue<iii>
#define MOD 1000000007
int xx[4]={0,1,0,-1},yy[4]={1,0,-1,0};
int MAX=1e5;

void solve(){
    int r,c;
    cin>>r>>c;
    vvi a(r,vi(c));
    tr(i,a) tr(j,i) cin>>j;
    hmax h;
    vvi vis(r,vi(c,0)),val(r,vi(c,0));
    fr(i,r) fr(j,c) val[i][j]=a[i][j];
    fr(i,r) fr(j,c) if(a[i][j]) h.push({a[i][j],{i,j}});
    while(!h.empty()){
        int x=h.top().S.F,y=h.top().S.S,z=h.top().F;
        h.pop();
        vis[x][y]=1;
        fr(k,4){
            int p=x+xx[k],q=y+yy[k];
            if(p>=0 && q>=0 && p<r && q<c){
                if(vis[p][q]) continue;
                if(val[p][q]<val[x][y]-1){
                    val[p][q]=val[x][y]-1;
                    h.push({val[p][q],{p,q}});
                    vis[p][q]=1;
                }
            }
        }
    }
    int res=0;
    fr(i,r) fr(j,c) res+=val[i][j]-a[i][j];
    cout<<res;
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
        cout<<"Case #"<<i<<": ";
        solve();
        cout<<"\n";
    }
    return 0;
}