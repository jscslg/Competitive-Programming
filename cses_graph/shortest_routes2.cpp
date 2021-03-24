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
int MAX=1e16+1,n,m,q;

void solve(){
    cin>>n>>m>>q;
    vvi g(n,vi(n,MAX));
    fr(i,0,n) g[i][i]=0;
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        g[a][b]=min(g[a][b],c);
        g[b][a]=min(g[b][a],c);
    }
    fr(k,0,n){
        fr(i,0,n){
            fr(j,0,n){
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y,x--,y--;
        cout<<((g[x][y]>=MAX)?-1:g[x][y])<<"\n";
    }
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
        cout<<"\n";
    }
    return 0;
}