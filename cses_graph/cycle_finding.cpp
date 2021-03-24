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
int MAX=1e5,n,m;
vector<vii> g;

void solve(){
    cin>>n>>m;
    g.assign(n,vii());
    fr(i,0,m){
        int a,b,c;
        cin>>a>>b>>c,a--,b--;
        g[a].pb({b,c});
    }
    vi d(n,1e15),p(n,-1);
    d[0]=0;
    int f;
    fr(k,0,n+1){
        f=-1;
        fr(i,0,n){
            tr(j,g[i]){
                int e=j.F,c=j.S;
                if(d[e]>d[i]+c){
                    d[e]=d[i]+c;
                    p[e]=i;
                    f=e;
                }
            }
        }
    }
    if(f!=-1){
        cout<<"YES\n";
        fr(i,0,n){
            cout<<f+1<<" ";
 		    f=p[f];
 	    }
        cout<<"\n";
        vi cyc;
        for(int aa=f;;aa=p[aa]){
 		    cyc.pb(aa);
 		    if(cyc.size()>1&&aa==f){
 			    break;
 		    }
 	    }
 	    reverse(all(cyc));
 	    tr(i,cyc) cout<<i+1<<" ";
    }
    else cout<<"NO";
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