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

void solve(){
    int n,q;
    cin>>n>>q;
    vi par(n);
    tr(e,par) cin>>e,e--;
    int p=log2(1e9-1)+2;
    vvi up(n,vi(p,0));
    fr(i,0,n) up[i][0]=par[i];
    fr(i,1,p){
        fr(j,0,n) up[j][i]=up[up[j][i-1]][i-1];
    }

    while(q--){
        int x,k;
        cin>>x>>k,x--;
        //int res=x;
        fr(i,0,p){
            if((1<<i)&k) x=up[x][i];
        }
        cout<<x+1<<"\n";
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
    }
    return 0;
}