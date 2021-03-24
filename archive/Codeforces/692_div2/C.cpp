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

void solve(){
    int n,m,res=0;
    cin>>n>>m;
    vvi g(n+1,vi());
    vi a(n+1,0);
    fr(i,0,m){
        int x,y;cin>>x>>y;
        if(x!=y) { 
            g[x].pb(y);
            g[y].pb(x);
        }
    }
    vi f(n+1,0);
    fr(i,1,n+1){
        if(a[i]==0 && g[i].size()==1) {
            queue<int> q;
            q.push(i);
            int x=0;
            a[i]=1;
            while(!q.empty()){
                int e=q.front();
                q.pop();
                tr(j,g[e]) {
                    if(a[j]==0) {
                        a[j]=1;
                        q.push(j);
                    }
                }
                x+=g[e].size();
            }
            res+=x/2;
        }
    }
    fr(i,1,n+1){
		if(a[i]==0 && g[i].size()>1){
			queue<int> q;
			q.push(i); 
            int x=0;
            a[i]=1;
			while(!q.empty()){
				int e=q.front();
                q.pop();
				tr(j,g[e]) {
                    if(a[j]==0) {
                        a[j]=1;
                        q.push(j);
                    }
                }
				x++;
			}
			res+=(x>1?x+1:x);
		}
	}
    cout<<res<<"\n";
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