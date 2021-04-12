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
vii p;

int find(int a){
    if(a==p[a].F) return a;
    p[a].F = find(p[a].F);
    return p[a].F;
}

void unison(int a,int b){
    if(p[a].S>p[b].S) p[b].F=a;
    else if(p[a].S<p[b].S) p[a].F=b;
    else{
        p[a].F=b;
        p[b].S++;
    }
}

void solve(){
    cin>>n>>m;
    vector<pair<int,ii>> edges(m); 
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        edges[i]={c,{a,b}};
    }
    sort(all(edges));
    p.resize(n);
    fr(i,0,n) p[i]={i,0}; 
    int i=0,j=0,res=0;
    while(i<n-1 && j<m){
        int cost=edges[j].F,x=edges[j].S.F,y=edges[j].S.S;
        int xp=find(x),yp=find(y);
        if(xp!=yp){
            unison(xp,yp);
            res+=cost;
            i++;
        }
        j++;
    }
    if(i==n-1) cout<<res;
    else cout<<"IMPOSSIBLE";
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